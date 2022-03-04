#pragma once

#include <string>

using namespace std;

class Dog
{
private:
    int id;
    std::string breed;
    std::string name;
    int age;
    std::string photograph;
public:
    Dog();
    Dog(int _id, std::string _breed, std::string _name,int _age, std::string _photograph);
    ~Dog();

    int getID();
    std::string getBreed();
    std::string getName();
    int getAge();
    std::string getPhoto();
    std::string toString();

    friend std::istream &operator>>(std::istream &is, Dog &dog);
    friend std::ostream &operator<<(std::ostream &os, const Dog &dog);

};