#include <QVBoxLayout>
#include <QtWidgets>
#include "GUI.h"

using namespace std;


GUI::GUI(GUIAdmin &GUIAdmin, GUIUser &GUIUser) :  _admin{GUIAdmin}, _user{GUIUser}
{
    this->initGUI();
    this->connectSignalsAndSlots();
}

void GUI::initGUI()
{
    this->setStyleSheet("background-color: #9B5949;");
    this->userButton = new QPushButton{"User"};
    this->adminButton = new QPushButton{"Admin"};

    QVBoxLayout * mainLayout = new QVBoxLayout { this };

    QGridLayout* buttonsLayout = new QGridLayout{};
    buttonsLayout->addWidget(this->userButton, 0, 0);
    buttonsLayout->addWidget(this->adminButton, 0, 1);
    mainLayout->addLayout(buttonsLayout);
}

void GUI::connectSignalsAndSlots()
{
    QObject::connect(this->userButton, &QPushButton::clicked, this, &GUI::openUserGUI);
    QObject::connect(this->adminButton, &QPushButton::clicked, this, &GUI::openAdminGUI);
}

void GUI::openUserGUI()
{
    _user.setWindowTitle("User");
    this->_user.show();
}

void GUI::openAdminGUI()
{
    _admin.setWindowTitle("Admin");
    this->_admin.show();
}

GUI::~GUI()
{
}