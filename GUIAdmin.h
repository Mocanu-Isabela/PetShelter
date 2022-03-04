#ifndef A89_ISABELAMOCANU915_GUIAdminADMIN_H
#define A89_ISABELAMOCANU915_GUIAdminADMIN_H

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include "repo.h"

class GUIAdmin : public QWidget
{
private:
    Repository& _repo;
public:
    GUIAdmin(Repository&);
    ~GUIAdmin();

private:
    QListWidget* dogsListWidget;
    QLineEdit* idLineEdit, * breedLineEdit, * nameLineEdit, * ageLineEdit, * photographLineEdit;
    QPushButton* addButton, * deleteButton, * updateButton, * listButton, * backButton;

    void initGUIAdmin();
    void populateListAdmin();
    void connectSignalsAndSlotsAdmin();

    int getSelectedIndex() const;
    void addDogGUIAdmin();
    void deleteDogGUIAdmin();
    void updateDogGUIAdmin();
};

#endif //A89_ISABELAMOCANU915_GUIAdminADMIN_H
