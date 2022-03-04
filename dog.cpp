#include "dog.h"
//#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>


using namespace std;

Dog::Dog(int _id,std::string _breed,std::string _name,int _age,std::string _photograph)
{
    this->id = _id;
    string s1(_breed);
    this->breed = s1;
    string s2(_name);
    this->name = s2;
    this->age = _age;
    string s3(_photograph);
    this->photograph = s3;
}

Dog::Dog()
{

}

int Dog::getID()
{
    return this->id;
}

string Dog::getBreed()
{
    return this->breed;
}

string Dog::getName()
{
    return this->name;
}

int Dog::getAge()
{
    return this->age;
}

string Dog::getPhoto()
{
    return this->photograph;
}

std::string Dog::toString()
{
    stringstream buffer;
    buffer << "Dog with id " << this->id << "\n\t breed " << this->breed << endl << "\t with the name " << this->name << endl <<"\t that is " << this->age << " years old " << endl << "\t and has the photograph "<<this->photograph<< "\n";
    return buffer.str();
}

vector<string> tokenize(string s,char delimiter){
    vector<string> data;
    stringstream str(s);
    string token;
    while (getline(str,token,delimiter))
        data.push_back(token);
    return data;
}

std::istream &operator>>(istream &is,Dog &dog)
{
    string line;
    getline(is,line);
    vector<string> data = tokenize(line,',');
    if(data.size() != 5) return is;
    dog.id = stoi(data[0]);
    dog.breed = data[1];
    dog.name = data[2];
    dog.age = stoi(data[3]);
    dog.photograph = data[4];
    return is;
}

std::ostream &operator<<(ostream &os,const Dog &dog)
{
    os << dog.id << "," << dog.breed << "," << dog.name <<"," << dog.age <<"," << dog.photograph << "\n";
    return os;
}

Dog::~Dog()
{
//    cout << "Dog: breed " << this->breed<< " with the name " << this->name << " that is " << this->age << " years old and has the photograph "<< this->photograph << " destroyed.\n";
}