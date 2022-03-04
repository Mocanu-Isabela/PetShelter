#ifndef A89_ISABELAMOCANU915_GUI_H
#define A89_ISABELAMOCANU915_GUI_H

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include "GUIAdmin.h"
#include "GUIUser.h"

class GUI : public QWidget
{
private:
    GUIAdmin& _admin;
    GUIUser& _user;
public:
    GUI(GUIAdmin&, GUIUser&);
    ~GUI();

private:
    QPushButton* userButton, * adminButton;

    void initGUI();
    void connectSignalsAndSlots();

    void openUserGUI();
    void openAdminGUI();
};

#endif //A89_ISABELAMOCANU915_GUI_H
