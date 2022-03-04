#include <QVBoxLayout>
#include <QtWidgets>
#include "GUIcsvORhtml.h"


GUIcsvORhtml::GUIcsvORhtml(Repository &repo) :  _repo{repo}
{
    this->initGUIcsvORhtml();
    this->connectSignalsAndSlots();
}

void GUIcsvORhtml::initGUIcsvORhtml()
{
    this->setStyleSheet("background-color: #247434;");
    this->csvButton = new QPushButton{"CSV"};
    this->htmlButton = new QPushButton{"HTML"};

    QVBoxLayout * mainLayout = new QVBoxLayout { this };

    QGridLayout* buttonsLayout = new QGridLayout{};
    buttonsLayout->addWidget(this->csvButton, 0, 0);
    buttonsLayout->addWidget(this->htmlButton, 0, 1);
    mainLayout->addLayout(buttonsLayout);
}

void GUIcsvORhtml::openCSV() {
    this->_repo.write_in_CSV("C:\\Users\\Isabela\\Desktop\\GitHub\\OOP assignments\\a67-IsabelaMocanu915\\dogs.csv");
    this->_repo.open_CSV("C:\\Users\\Isabela\\Desktop\\GitHub\\OOP assignments\\a67-IsabelaMocanu915\\dogs.csv");
}

void GUIcsvORhtml::openHTML() {
    this->_repo.write_in_HTML("C:\\Users\\Isabela\\Desktop\\GitHub\\OOP assignments\\a67-IsabelaMocanu915\\dogs.html");
    this->_repo.open_HTML("C:\\Users\\Isabela\\Desktop\\GitHub\\OOP assignments\\a67-IsabelaMocanu915\\dogs.html");
}

void GUIcsvORhtml::connectSignalsAndSlots()
{
    QObject::connect(this->csvButton, &QPushButton::clicked, this, &GUIcsvORhtml::openCSV);
    QObject::connect(this->htmlButton, &QPushButton::clicked, this, &GUIcsvORhtml::openHTML);
}

GUIcsvORhtml::~GUIcsvORhtml() {
}