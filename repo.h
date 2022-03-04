#include "dog.h"
#include <vector>
using namespace std;

#ifndef A45_ISABELAMOCANU915_REPO_H
#define A45_ISABELAMOCANU915_REPO_H

class Repository
{
protected:
    std::vector<Dog> elems;
    std::vector<Dog> adopted_elems;
    std::string _filename;

public:
    Repository(std::string filename);
    void add_dog_repo(Dog &dog);
    void remove_dog_repo(int id);
    void update_dog_repo(Dog &dog);
    int search(int id);
    std::vector<Dog> get_dogs_repo();
    std::string get_elem_by_index_string_form(int index);
//    std::string get_elem_by_id_string_form(int id);
//    std::string get_url_by_index(int index);
    int get_id_by_index(int index);
    int get_age_by_index(int index);
    std::string get_breed_by_index(int index);
    void add_adoption_repo(Dog &dog);
//    std::vector<Dog> get_adoptions_repo();

    void read_file();
    void write_in_file();

    void open_CSV(std::string CSVorHTMLfile) const;
    void write_in_CSV(std::string CSVorHTMLfile);
    void open_HTML(std::string CSVorHTMLfile) const;
    void write_in_HTML(std::string CSVorHTMLfile);

    Dog get_dog_by_id(int i);

    int search_in_adoption_list(int id);
};


#endif //A45_ISABELAMOCANU915_REPO_H
