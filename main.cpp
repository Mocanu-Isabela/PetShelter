#include <iostream>
#include "repo.h"
#include "GUI.h"
#include <QApplication>
#include <QGridLayout>


int main(int argc, char *argv[])
/*
 *Main function
 */
{
    QApplication a(argc, argv);

    std::string filename = "C:\\Users\\Isabela\\Desktop\\GitHub\\OOP assignments\\a89-IsabelaMocanu915\\dogs.txt";
    Repository repo{filename};
    GUIcsvORhtml guiCSVorHTML{repo};
    GUIUser guiUser{repo, guiCSVorHTML};
    GUIAdmin guiAdmin{repo};
    GUI gui{guiAdmin, guiUser};
    gui.setWindowTitle("Dog Shelter");
    gui.setFixedSize(400, 80);
    gui.show();
    return a.exec();


//    std::string filename = "C:\\Users\\Isabela\\Desktop\\GitHub\\OOP assignments\\a67-IsabelaMocanu915\\dogs.txt";
//    Repository repo{filename};
//    UI ui{repo};
//    ui.ui_function();
}



//1, Rottweiler, Axl, 1, https://upload.wikimedia.org/wikipedia/commons/5/57/Rottweiler.jpg
//2, Poodle, Bailey, 4, https://thehappypuppysite.com/wp-content/uploads/2018/01/Toy-Poodle-HP-long.jpg
//3, Beagle, Apollo, 1, https://www.animaland.ro/wp-content/uploads/2019/07/beagle-06.jpg
//4, Bulldog, Brownie, 7, https://rasedecaini.ro/wp-content/uploads/2019/05/Bulldog-Englez.jpg
//5, Golden Retriever, Zara, 8, https://www.animalepierdute.ro/wp-content/uploads/2019/08/golden-retriver-caine-de-rasa.jpg
//6, German Shepherd, Leah, 4, https://www.thesprucepets.com/thmb/F_16ouls0et8Cs8jGVbG9cJo8M4=/1000x1000/smart/filters:no_upscale()/breed_profile_germansheperd_1118000_hero_2536-6dc4ce05871945b8a894bd80c0ecc7f1.jpg
//7, Labrador, Theo, 5, https://i.pinimg.com/originals/c3/70/74/c37074167a76a7d20a965a94f360d7b8.jpg
//8, Yorkshire Terrier, Mia, 8, https://www.cutzucutzu.com/wp-content/uploads/2019/04/terrier-yorkshire-1024x793.jpg
//9, Husky, Bella, 3, https://pisicutesicaini.ro/wp-content/uploads/2019/07/Siberian-Husky-standing-outdoors-in-the-winter1.jpg
//10, Samoyed, Sasha, 2, https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/20122208/Samoyed-standing-in-the-forest.jpg