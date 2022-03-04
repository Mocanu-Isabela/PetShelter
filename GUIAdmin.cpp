#include <QVBoxLayout>
#include <QFormLayout>
#include <QtWidgets>
#include <QMessageBox>
#include <iostream>
#include "GUIAdmin.h"
#include "exceptions.h"

using namespace std;


GUIAdmin::GUIAdmin(Repository &repo) :  _repo{repo}
{
    this->initGUIAdmin();
    this->populateListAdmin();
    this->connectSignalsAndSlotsAdmin();
}

void GUIAdmin::initGUIAdmin() {
    this->setStyleSheet("background-color: #9B59B6;");
    this->dogsListWidget = new QListWidget{};
    this->idLineEdit = new QLineEdit{};
    this->breedLineEdit = new QLineEdit{};
    this->nameLineEdit = new QLineEdit{};
    this->ageLineEdit = new QLineEdit{};
    this->photographLineEdit= new QLineEdit{};
    this->addButton = new QPushButton{"Add"};
    this->deleteButton = new QPushButton{"Delete"};
    this->updateButton = new QPushButton{"Update"};

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
    buttonsLayout->addWidget(this->addButton, 0, 0);
    buttonsLayout->addWidget(this->deleteButton, 0, 1);
    buttonsLayout->addWidget(this->updateButton, 1, 0);
    mainLayout->addLayout(buttonsLayout);
}

void GUIAdmin::populateListAdmin() {
    this->dogsListWidget->clear();

    vector<Dog> dogs_list = this->_repo.get_dogs_repo();
    for(Dog& dog: dogs_list)
        this->dogsListWidget->addItem(QString::fromStdString(to_string(dog.getID())+ "  " + dog.getBreed()+ "  " + dog.getName() + "  " + to_string(dog.getAge()) + "  " + dog.getPhoto()));
}

void GUIAdmin::connectSignalsAndSlotsAdmin() {
    QObject::connect(this->dogsListWidget, &QListWidget::itemSelectionChanged, [this](){
        int selectedIndex = this->getSelectedIndex();
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
    QObject::connect(this->addButton, &QPushButton::clicked, this, &GUIAdmin::addDogGUIAdmin);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &GUIAdmin::deleteDogGUIAdmin);
    QObject::connect(this->updateButton, &QPushButton::clicked, this, &GUIAdmin::updateDogGUIAdmin);
}

int GUIAdmin::getSelectedIndex() const {
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

void GUIAdmin::addDogGUIAdmin() {
    int id = this->idLineEdit->text().toInt();
    string breed = this->breedLineEdit->text().toStdString();
    string name = this->nameLineEdit->text().toStdString();
    int age = this->ageLineEdit->text().toInt();
    string photograph = this->photographLineEdit->text().toStdString();
    int selectedIndex = this->getSelectedIndex();
    int ok = 1;
    if (this->idLineEdit->text().isEmpty() || this->breedLineEdit->text().isEmpty() || this->nameLineEdit->text().isEmpty() || this->ageLineEdit->text().isEmpty() || this->photographLineEdit->text().isEmpty())
    {
        ok = 0;
    }
    if(selectedIndex < 0){
        QMessageBox::critical(this, "Error", "No dog was selected!");
        return;
    }
    if(ok == 0){
        QMessageBox::critical(this, "Error", "The informations are incorrect!");
        return;
    }
    try{
        Dog dog = Dog(id, breed, name, age, photograph);
        this->_repo.add_dog_repo(dog);
    }
    catch(Exception &e)
    {
        QMessageBox::critical(this, "Error", e.what());

    }
    this->populateListAdmin();
    int lastElement = this->_repo.get_dogs_repo().size() -1;
    this->dogsListWidget->setCurrentRow(lastElement);
}

void GUIAdmin::deleteDogGUIAdmin() {
    int id = this->idLineEdit->text().toInt();
    int selectedIndex = this->getSelectedIndex();
    if(selectedIndex < 0){
        QMessageBox::critical(this, "Error", "No dog was selected!");
        return;
    }
    try{
        this->_repo.remove_dog_repo(id);
    }
    catch(Exception &e)
    {
        QMessageBox::critical(this, "Error", e.what());

    }
    this->populateListAdmin();
}

void GUIAdmin::updateDogGUIAdmin() {
    int id = this->idLineEdit->text().toInt();
    string breed = this->breedLineEdit->text().toStdString();
    string name = this->nameLineEdit->text().toStdString();
    int age = this->ageLineEdit->text().toInt();
    string photograph = this->photographLineEdit->text().toStdString();
    int selectedIndex = this->getSelectedIndex();
    if(selectedIndex < 0){
        QMessageBox::critical(this, "Error", "No dog was selected!");
        return;
    }
    try{
        Dog dog = Dog(id, breed, name, age, photograph);
        this->_repo.update_dog_repo(dog);
    }
    catch(Exception &e)
    {
        QMessageBox::critical(this, "Error", e.what());

    }
    this->populateListAdmin();
}

GUIAdmin::~GUIAdmin()
{
}

