#include <QVBoxLayout>
#include <QFormLayout>
#include <QtWidgets>
#include <QMessageBox.h>
#include <iostream>
#include "GUIUser.h"
#include "exceptions.h"

using namespace std;

GUIUser::GUIUser(Repository &repo, GUIcsvORhtml &csvORhtml) :  _repo{repo}, _csvORhtml{csvORhtml}
{
    this->initGUIUser();
    this->populateListUser();
    this->connectSignalsAndSlotsUser();
}

void GUIUser::initGUIUser()
{
    this->setStyleSheet("background-color: #02F239;");
    this->idLineEdit = new QLineEdit{};
    this->idLineEdit->setEnabled(false);
    this->breedLineEdit = new QLineEdit{};
    this->breedLineEdit->setEnabled(false);
    this->nameLineEdit = new QLineEdit{};
    this->nameLineEdit->setEnabled(false);
    this->ageLineEdit = new QLineEdit{};
    this->ageLineEdit->setEnabled(false);
    this->photographLineEdit= new QLineEdit{};
    this->photographLineEdit->setEnabled(false);
    this->dogsListWidget = new QListWidget{};
    this->seeAdoptionListButton = new QPushButton{"See Adoption List"};
    this->adoptButton = new QPushButton{"Adopt"};

    QVBoxLayout * mainLayout = new QVBoxLayout { this };
    mainLayout->addWidget(this->dogsListWidget);

    QFormLayout* dogsDetailsLayout = new QFormLayout{};
    dogsDetailsLayout->addRow("Id", this->idLineEdit);
    dogsDetailsLayout->addRow("Breed", this->breedLineEdit);
    dogsDetailsLayout->addRow("Name", this->nameLineEdit);
    dogsDetailsLayout->addRow("Age", this->ageLineEdit);
    dogsDetailsLayout->addRow("Photograph", this->photographLineEdit);
    mainLayout->addLayout(dogsDetailsLayout);

    QGridLayout* buttonsLayout = new QGridLayout{};
    buttonsLayout->addWidget(this->seeAdoptionListButton, 0, 0);
    buttonsLayout->addWidget(this->adoptButton, 0, 1);
    mainLayout->addLayout(buttonsLayout);
}

void GUIUser::populateListUser()
{
    this->dogsListWidget->clear();

    vector<Dog> dogs_list = this->_repo.get_dogs_repo();
    for(Dog& dog: dogs_list)
        this->dogsListWidget->addItem(QString::fromStdString(to_string(dog.getID())+ "  " + dog.getBreed()+ "  " + dog.getName() + "  " + to_string(dog.getAge()) + "  " + dog.getPhoto()));
}

void GUIUser::connectSignalsAndSlotsUser()
{
    QObject::connect(this->dogsListWidget, &QListWidget::itemSelectionChanged, [this](){
        int selectedIndex = this->getSelectedIndexUser();
        if(selectedIndex < 0)
        {
            return;
        }
        Dog dog = this->_repo.get_dogs_repo()[selectedIndex];
        this->idLineEdit->setText(QString::fromStdString(to_string(dog.getID())));
        this->breedLineEdit->setText(QString::fromStdString(dog.getBreed()));
        this->nameLineEdit->setText(QString::fromStdString(dog.getName()));
        this->ageLineEdit->setText(QString::fromStdString(to_string(dog.getAge())));
        this->photographLineEdit->setText(QString::fromStdString(dog.getPhoto()));
    });
    QObject::connect(this->adoptButton, &QPushButton::clicked, this, &GUIUser::adoptDogGUIUser);
    QObject::connect(this->seeAdoptionListButton, &QPushButton::clicked, this, &GUIUser::seeAdoptionList);

}

int GUIUser::getSelectedIndexUser() const {
    QModelIndexList selectedIndexes = this->dogsListWidget->selectionModel()->selectedIndexes();
    if(selectedIndexes.size() == 0){
        this->idLineEdit->clear();
        this->breedLineEdit->clear();
        this->nameLineEdit->clear();
        this->ageLineEdit->clear();
        this->photographLineEdit->clear();
        return -1;
    }

    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void GUIUser::adoptDogGUIUser() {
    int id = this->idLineEdit->text().toInt();
    int selectedIndex = this->getSelectedIndexUser();
    if(selectedIndex < 0){
        QMessageBox::critical(this, "Error", "No dog was selected!");
        return;
    }
    try{
        Dog dog = this->_repo.get_dogs_repo()[selectedIndex];
        int rez = this->_repo.search_in_adoption_list(id);
        if (rez == -1)
        {
            this->_repo.add_adoption_repo(dog);
        }
        else
        {
            QMessageBox::critical(this, "Error", "This dog is already adopted");
        }
    }
    catch(Exception &e)
    {
        QMessageBox::critical(this, "Error", e.what());

    }
    this->populateListUser();
}

void GUIUser::seeAdoptionList() {
    _csvORhtml.setWindowTitle("File type");
    _csvORhtml.setFixedSize(400, 80);
    this->_csvORhtml.show();
}

GUIUser::~GUIUser()
{
}




