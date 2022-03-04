//#include <windows.h>
#include <cstdio>
#include <string>
#include <iostream>
#include "ui.h"

#include "validators.h"
#include "exceptions.h"

using namespace std;

void UI::administrator_main_menu()
/*
 *Function that prints the administrator menu
 */
{
    cout<<"1 - Add a dog.\n"
          "2 - Delete a dog.\n"
          "3 - Update a dog.\n"
          "4 - List all dogs that are in the shelter.\n"
          "8 - Back to a/u\n"
          "0 - Exit\n";
}

void UI::user_main_menu()
/*
 *Function that prints the user menu
 */
{
    cout<<"1 - See the dogs in the database.\n"
          "2 - See all the dogs of a given breed, having an age less than a given number.\n"
          "    If no breed is provided, then all the dogs will be considered.\n"
          "3 - See the adoption list.\n"
          "8 - Back to a/u\n"
          "0 - Exit\n";
}

void UI::user_adoption_menu()
/*
 *Function that prints the user menu
 */
{
    cout<<"1 - Adopt this dog.\n"
          "2 - Don't adopt this dog, go to the next one.\n"
          "3 - Exit the presentation\n";
}

UI::UI(Repository &repo) : _repo(repo){
}


//The shelter employees must be able to update the database, meaning: add a new dog, delete a dog (when the dog is adopted) and update the information of a dog.
//Each Dog has a breed, a name, an age and a photograph.
//The photograph is memorised as a link towards an online resource (the photograph on the presentation site of the centre).
// The administrators will also have the option to see all the dogs in the shelter.


void UI::ui_function()
/*
 *UI function
 */
{
    cout<<"1 - CSV\n"
          "2 - HTML\n";
    int file_type = 0;
    cout<<"\n";
    std::string csv_or_html_file = "0";
    while(file_type != 1 && file_type != 2)
    {
        cout<<"Please enter the type of file you want: ";
        fflush(stdin);
        cin>>file_type; // 1 for CSV and 2 for HTML
        if (file_type == 1)
        {
            csv_or_html_file = "C:\\Users\\Isabela\\Desktop\\GitHub\\proiecte\\a89-IsabelaMocanu915-PetShelter\\dogs.csv";
        }
        else if (file_type == 2)
        {
            csv_or_html_file = "C:\\Users\\Isabela\\Desktop\\GitHub\\proiecte\\a89-IsabelaMocanu915-PetShelter\\dogs.html";
        }
        else
        {
            cout<<"There is a problem with the option you entered";
            cout<<"\n";
        }
    }

    bool done = false;
    while (!done)
    {
        char command;

        cout<<"Please enter a for the administrator mode and u for the user mode or 0 to exit: ";
        fflush(stdin);
        cin>>command;
        cout<<"\n";

        if (command == 'a')
        {
            bool stop = false;
            while (!stop)
            {
                char ui_command = 0;
                administrator_main_menu();
                cout<<"\n";
                cout<<"Please enter a ui_command: ";
                fflush(stdin);
                cin>>ui_command;

                if (ui_command == '1') //add
                {
                    char breed[48], name[20], photograph[288];
                    int dog_id, age;
                    cout<<"id: ";
                    fflush(stdin);
                    cin>>dog_id;
                    cout<<"breed: ";
                    fflush(stdin);
                    cin.getline(breed, 48);
                    cout<<"name: ";
                    fflush(stdin);
                    cin.getline(name, 20);
                    cout<<"age: ";
                    fflush(stdin);
                    cin>>age;
                    cout<<"photograph: ";
                    fflush(stdin);
                    cin.getline(photograph, 288);
                    cout<<"\n";
                    Validator va;
                    if(va.valid(dog_id,breed, name, age, photograph))
                    {
                        Dog dog = Dog(dog_id, breed, name, age, photograph);
                        try
                        {
                            this->_repo.add_dog_repo(dog);
                            cout<<"The dog was successfully added." << '\n';
                        }
                        catch (Exception& except)
                        {
                            cout << "An exception occurred: " << except.what() << '\n';
                        }
                        this->_repo.write_in_file();


//                        result = this->_repo.search(dog_id);
//                        if (result == -1)
//                        {
//                            this->_repo.add_dog_repo(dog);
//                            cout<<"\n";
//                            cout<<"The dog was successfully added.\n";
//                            cout<<"\n";
//                        }
//                        else
//                        {
//                            cout<<"\n";
//                            cout<<"There already is a dog with this id.\n";
//                            cout<<"\n";
//                        }
                    }
                    else
                    {
                        cout<<"The input is invalid!";
                        stop = true;
                        done = true;
                    }
                }

                else if (ui_command == '2') //delete
                {
                    int dog_id;
                    cout<<"Please enter the id of the dog: ";
                    fflush(stdin);
                    cin>>dog_id;
                    try
                    {
                        this->_repo.remove_dog_repo(dog_id);
                        cout<<"The dog was successfully removed."<< '\n';

                    }
                    catch (Exception& except)
                    {
                        cout << "An exception occurred: " << except.what() << '\n';
                    }
                    this->_repo.write_in_file();

//                    result = this->_repo.search(dog_id);
//                    if (result == -1)
//                    {
//                        cout<<"\n";
//                        cout<<"There is no dog with this id.\n";
//                        cout<<"\n";
//                    }
//                    else
//                    {
//                        this->_repo.remove_dog_repo(dog_id);
//                        cout<<"\n";
//                        cout<<"The dog was successfully deleted.\n";
//                        cout<<"\n";
//                    }
                }

                else if (ui_command == '3') //update
                {
                    char breed[48], name[20], photograph[288];
                    int dog_id, age;
                    cout<<"id: ";
                    fflush(stdin);
                    cin>>dog_id;
                    cout<<"breed: ";
                    fflush(stdin);
                    cin.getline(breed, 48);
                    cout<<"name: ";
                    fflush(stdin);
                    cin.getline(name, 20);
                    cout<<"age: ";
                    fflush(stdin);
                    cin>>age;
                    cout<<"photograph: ";
                    fflush(stdin);
                    cin.getline(photograph, 288);
                    Dog dog = Dog(dog_id, breed, name, age, photograph);
                    try
                    {
                        this->_repo.update_dog_repo(dog);
                        cout<<"The dog was successfully updated."<< '\n';
                    }
                    catch (Exception& except)
                    {
                        cout << "An exception occurred: " << except.what() << '\n';
                    }
                    this->_repo.write_in_file();

//                    result = dynamic_array.update(dog_id, dog);
//                    if (result == 0)
//                    {
//                        cout<<"\n";
//                        cout<<"The dog was successfully updated.\n";
//                        cout<<"\n";
//                    }
//                    else if (result == 1)
//                    {
//                        cout<<"\n";
//                        cout<<"There is no dog with this id.\n";
//                        cout<<"\n";
//                    }
                }

                else if (ui_command == '4') //list
                {
                    int i;
                    std::vector<Dog> dogs =_repo.get_dogs_repo();
                    for (i = 0; i < dogs.size(); i++)
                    {
                        std::string str;
                        str = this->_repo.get_elem_by_index_string_form(i);
                        cout << str << endl;
                    }
                }

                else if (ui_command == '8') //Back to a/u
                {
                    stop = true;
                }

                else if (ui_command == '0') //exit
                {
                    stop = true;
                    done = true;
                    cout<<"Have a nice day! :)\n";
                }

                else
                {
                    cout<<"\nInvalid ui_command!\n";
                }
            }
        }
        else if (command == 'u')
        {
            int adoption_list[40], nr_adopted_dogs = 0;
            bool stop = false;
            while (!stop)
            {
                char ui_command = 0;
                user_main_menu();
                cout<<"\n";
                cout<<"Please enter a ui_command: ";
                fflush(stdin);
                cin>>ui_command;

                if (ui_command == '1') //see the dogs in the database
                {
                    int i = 0, length;
                    std::vector<Dog> dogs =_repo.get_dogs_repo();
                    length = dogs.size();
                    while (i < length)
                    {
                        std::string url, str;
                        str = this->_repo.get_elem_by_index_string_form(i);
                        cout << str << endl;
//                        url = this->_repo.get_url_by_index(i);
//                        ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
                        bool adoption_stop = false;
                        while (!adoption_stop)
                        {
                            char adoption_command = 0;
                            user_adoption_menu();
                            cout<<"\n";
                            cout<<"Please enter an adoption_command: ";
                            fflush(stdin);
                            cin>>adoption_command;
                            if (adoption_command == '1') //adopt this dog
                            {
                                int dog_id, j;
                                bool adopted = false;
                                dog_id = this->_repo.get_id_by_index(i);
                                for (j = 0; j < nr_adopted_dogs; j++)
                                {
                                    if (adoption_list[j] == dog_id)
                                    {
                                        adopted = true;
                                    }
                                }
                                if (!adopted)
                                {
                                    Dog dog =  this->_repo.get_dog_by_id(dog_id);
                                    //make a repo function that returns the dog with a certain id
                                    //see how you get an element from the vector if you know its position
                                    //look at the remove_dog_repo to see how you get and use its position
                                    this->_repo.add_adoption_repo(dog);
                                    adoption_list[nr_adopted_dogs] = dog_id;
                                    nr_adopted_dogs++;
                                    if (file_type == 1)
                                    {
                                        try
                                        {
                                            this->_repo.write_in_CSV(csv_or_html_file);
                                        }
                                        catch (Exception& except)
                                        {
                                            cout << "An exception occurred: " << except.what() << '\n';
                                        }

                                    }
                                    else
                                    {
                                        try
                                        {
                                            this->_repo.write_in_HTML(csv_or_html_file);
                                        }
                                        catch (Exception& except)
                                        {
                                            cout << "An exception occurred: " << except.what() << '\n';
                                        }
                                    }
                                }
                                else
                                {
                                    cout<<"\nThis dog is already adopted!\n";
                                }
                                adoption_stop = true;
                            }
                            else if (adoption_command == '2') //don't adopt this dog, go to the next one
                            {
                                adoption_stop = true;
                            }

                            else if (adoption_command == '3') //exit out of the presentation
                            {
                                adoption_stop = true;
                                i = length;
                            }

                            else
                            {
                                cout<<"\nInvalid command!\n";
                            }
                        }
                        i++;
                        if (i == length)
                        {
                            i = 0;
                        }
                    }
                }

                else if (ui_command == '2')
                //see all the dogs of a given breed, having an age less than a given number
                // if no breed is provided, then all the dogs will be considered
                {
                    std::string breed;
                    int age;
                    cout<<"breed: ";
                    fflush(stdin);
                    getline(std::cin, breed);
                    cout<<"age: ";
                    fflush(stdin);
                    cin>>age;
                    int i = 0, length;
                    bool none = true;
                    std::vector<Dog> dogs =_repo.get_dogs_repo();
                    length = dogs.size();
                    while (i < length)
                    {
                        if (this->_repo.get_breed_by_index(i) == breed || breed.empty())
                        {
                            if (this->_repo.get_age_by_index(i) < age)
                            {
                                none = false;
                                std::string url, str;
                                str = this->_repo.get_elem_by_index_string_form(i);
                                cout << str << endl;
//                                url = this->_repo.get_url_by_index(i);
//                                ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
                                bool adoption_stop = false;
                                while (!adoption_stop)
                                {
                                    char adoption_command = 0;
                                    user_adoption_menu();
                                    cout<<"\n";
                                    cout<<"Please enter an adoption_command: ";
                                    fflush(stdin);
                                    cin>>adoption_command;
                                    if (adoption_command == '1') //adopt this dog
                                    {
                                        int dog_id, j;
                                        bool adopted = false;
                                        dog_id = this->_repo.get_id_by_index(i);
                                        for (j = 0; j < nr_adopted_dogs; j++)
                                        {
                                            if (adoption_list[j] == dog_id)
                                            {
                                                adopted = true;
                                            }
                                        }
                                        if (!adopted)
                                        {
                                            adoption_list[nr_adopted_dogs] = dog_id;
                                            nr_adopted_dogs++;
                                        }
                                        else
                                        {
                                            cout<<"\nThis dog is already adopted!\n";
                                        }
                                        adoption_stop = true;
                                    }
                                    else if (adoption_command == '2') //don't adopt this dog, go to the next one
                                    {
                                        adoption_stop = true;
                                    }

                                    else if (adoption_command == '3') //exit out of the presentation
                                    {
                                        adoption_stop = true;
                                        i = length;
                                    }

                                    else
                                    {
                                        cout<<"\nInvalid command!\n";
                                    }
                                }
                            }
                        }
                        i++;
                        if (i == length && none)
                        {
                            cout<<"\nThere is no dog with the specified criteria."<< '\n';
                            cout<<"\n";
                            i = length+1;
                        }
                        if (i == length)
                        {
                            i = 0;
                        }
                    }
                }

                else if (ui_command == '3') //see the adoption list
                {
                    if (file_type == 1)
                    {
                        this->_repo.open_CSV(csv_or_html_file);
                    }
                    else
                    {
                        this->_repo.open_HTML(csv_or_html_file);
                    }

//                    if (nr_adopted_dogs == 0)
//                    {
//                        cout<<"\nThere are no adopted dogs.\n";
//                        cout<<"\n";
//                    }
//                    else
//                    {
//                        cout<<"\nThe number of adopted dogs is "<< nr_adopted_dogs;
//                        cout<<"\nAnd the dogs are:\n";
//                        int i = 0;
//                        while (i < nr_adopted_dogs)
//                        {
//                            int current_dog_id = adoption_list[i];
//                            std::string str;
//                            str = this->_repo.get_elem_by_id_string_form(current_dog_id);
//                            cout << str << endl;
//                            i++;
//                        }
//                    }
                }

                else if (ui_command == '8') //back to a/u
                {
                    stop = true;
                }

                else if (ui_command == '0') //exit
                {
                    done = true;
                    stop = true;
                    cout<<"Have a nice day! :)\n";
                }

                else
                {
                    cout<<"\nInvalid command!\n";
                }
            }
        }
        else if (command == '0') //exit
        {
            done = true;
            cout<<"Have a nice day! :)\n";
        }

        else
        {
            cout<<"\nInvalid ui_command!\n";
        }
    }
}