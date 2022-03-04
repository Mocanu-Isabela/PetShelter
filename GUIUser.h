#ifndef A89_ISABELAMOCANU915_GUIUSER_H
#define A89_ISABELAMOCANU915_GUIUSER_H

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include "repo.h"
#include "GUIcsvORhtml.h"

class GUIUser : public QWidget
{
private:
    Repository& _repo;
    GUIcsvORhtml& _csvORhtml;
public:
    GUIUser(Repository&, GUIcsvORhtml&);
    ~GUIUser();

private:
    QListWidget* dogsListWidget;
    QLineEdit* idLineEdit, * breedLineEdit, * nameLineEdit, * ageLineEdit, * photographLineEdit;
    QPushButton* seeAdoptionListButton, * adoptButton;
//
    void initGUIUser();
    void populateListUser();
    void connectSignalsAndSlotsUser();

    int getSelectedIndexUser() const;
    void adoptDogGUIUser();
    void seeAdoptionList() ;
};


#endif //A89_ISABELAMOCANU915_GUIUSER_H
