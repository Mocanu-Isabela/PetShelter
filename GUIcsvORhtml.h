#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include "repo.h"

#ifndef A89_ISABELAMOCANU915_GUICSVORHTML_H
#define A89_ISABELAMOCANU915_GUICSVORHTML_H

class GUIcsvORhtml : public QWidget
{
private:
    Repository& _repo;
public:
    GUIcsvORhtml(Repository&);
    ~GUIcsvORhtml();

private:
    QPushButton* csvButton, * htmlButton;

    void initGUIcsvORhtml();
    void connectSignalsAndSlots();

    void openCSV();
    void openHTML();
};

#endif //A89_ISABELAMOCANU915_GUICSVORHTML_H
