#include "repo.h"
#include "exceptions.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

Repository::Repository(std::string filename) : _filename(filename)
{
    read_file();
    ofstream ofs1;
    ofs1.open("C:\\Users\\Isabela\\Desktop\\GitHub\\proiecte\\a89-IsabelaMocanu915-PetShelter\\dogs.csv", std::ofstream::out | std::ofstream::trunc);
    ofs1.close();
    ofstream ofs2;
    ofs2.open("C:\\Users\\Isabela\\Desktop\\GitHub\\proiecte\\a89-IsabelaMocanu915-PetShelter\\dogs.html", std::ofstream::out | std::ofstream::trunc);
    ofs2.close();
}

void Repository::add_dog_repo(Dog &dog)
{
    int index;
    index = this->search(dog.getID());
    if (index == -1)
    {
        elems.push_back(dog);
        write_in_file();
    }
    else
    {
        Exception except("There already is a dog with this id.\n");
        throw except;
    }
}

void Repository::remove_dog_repo(int id)
{
    int index;
    index = this->search(id);
    if (index == -1)
    {
        Exception except("There is no dog with this id.\n");
        throw except;
    }
    else
    {
        this->elems.erase(this->elems.begin()+index);
        write_in_file();
    }
}

void Repository::update_dog_repo(Dog &dog)
{
    int index;
    index = this->search(dog.getID());
    if (index == -1)
    {
        Exception except("There is no dog with this id.\n");
        throw except;
    }
    else
    {
        elems.at(index) = dog;
        write_in_file();
    }
}

int Repository::search(int id)
{
    for (auto dog_index = this->elems.begin(); dog_index != this->elems.end(); ++dog_index)
        if (id == (*dog_index).getID())
        {
            int index;
            index = dog_index - this->elems.begin();
            return index;
        }
    return -1;
}

std::vector<Dog> Repository::get_dogs_repo()
{
    return elems;
}

void Repository::add_adoption_repo(Dog &dog)
{
    adopted_elems.push_back(dog);
}

//std::vector<Dog> Repository::get_adoptions_repo()
//{
//    return adopted_elems;
//}

int Repository::search_in_adoption_list(int id)
{
    for (auto dog_index = this->adopted_elems.begin(); dog_index != this->adopted_elems.end(); ++dog_index)
        if (id == (*dog_index).getID())
        {
            int index;
            index = dog_index - this->adopted_elems.begin();
            return index;
        }
    return -1;
}

std::string Repository::get_elem_by_index_string_form(int index)
{
    std::string str;
    str = this->elems[index].toString();
    return str;
}

//std::string Repository::get_url_by_index(int index)
//{
//    std::string url;
//    url = this->elems[index].getPhoto();
//    return url;
//}

int Repository::get_id_by_index(int index)
{
    int id;
    id = this->elems[index].getID();
    return id;
}

int Repository::get_age_by_index(int index)
{
    int age;
    age = this->elems[index].getAge();
    return age;
}

std::string Repository::get_breed_by_index(int index)
{
    std::string  breed;
    breed = this->elems[index].getBreed();
    return breed;
}

//std::string Repository::get_elem_by_id_string_form(int id) {
//    int index;
//    index = this->search(id);
//    return this->elems[index].toString();
//}

Dog Repository::get_dog_by_id(int id)
{
    int index = this->search(id);
    Dog dog = this->elems[index];
    return dog;
}

void Repository::read_file()
{
    ifstream f(this->_filename);
    Dog dog;
    if (! f.is_open())
    {
        return;
    }
    while(f>>dog)
    {
        elems.push_back(dog);
    }
    f.close();
}

void Repository::write_in_file()
{
    ofstream f(this->_filename);
    if (! f.is_open())
    {
        return;
    }
    vector<Dog> all_dogs = get_dogs_repo(); //getElements
    for (const auto& dog : all_dogs)
    {
        f << dog;
    }
    f.close();
}

void Repository::open_CSV(std::string CSVorHTMLfile) const {
    string filename = "\"" + CSVorHTMLfile + "\"";
    ShellExecuteA(NULL, NULL, "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Excel", filename.c_str(), NULL, SW_SHOWMAXIMIZED);
}

void Repository::write_in_CSV(std::string CSVorHTMLfile) {
    ofstream filename(CSVorHTMLfile);
    if (!filename.is_open())
        throw Exception("There is a problem with the CSV file");
    for (const auto& dog : this->adopted_elems)
        filename << dog;
    filename.close();

}

void Repository::open_HTML(std::string CSVorHTMLfile) const {
    string filename = "\"" + CSVorHTMLfile + "\"";
    ShellExecuteA(NULL, NULL, "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Google Chrome", filename.c_str(), NULL, SW_SHOWMAXIMIZED);
}

void Repository::write_in_HTML(std::string CSVorHTMLfile) {
    ofstream filename(CSVorHTMLfile);
    if(!filename.is_open()){
        throw Exception("The HTML file does not open ok");
    }
    filename << "<!DOCTYPE html>\n"
            "<html>\n"
            "<body>\n"
            "<table border=\"1\">\n"
            "<tr>\n"
            "<td>ID</td>\n"
            "<td>Breed</td>\n"
            "<td>Name</td>\n"
            "<td>Age</td>\n"
            "<td>Photograph</td>\n"
            "</tr>\n";
    for ( auto dog : this->adopted_elems){
        filename << "<tr>\n"
             << "<td>" << dog.getID() << "</td>\n"
             << "<td>" << dog.getBreed() << "</td>\n"
             << "<td>" << dog.getName() << "</td>\n"
             << "<td>" << dog.getAge() << "</td>\n"
             << "<td>" << dog.getPhoto() << "</td>\n"
             << "</tr>\n";
    }
    filename << "</table>\n"
            "</body>\n"
            "</html>\n";
}
