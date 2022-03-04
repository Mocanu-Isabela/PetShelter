#include "repo.h"
#pragma once

class UI{
public:
    UI(Repository& repo);
/// <summary>
/// The function that handles the ui part.
/// </summary>
/// <param>No parameters.</param>
/// <returns>Nothing.</returns>
    void ui_function();
private:
    Repository& _repo;
/// <summary>
/// The function that prints the administrator main menu.
/// </summary>
/// <param>No parameters.</param>
/// <returns>Nothing.</returns>
    void administrator_main_menu();
/// <summary>
/// The function that prints the user main menu.
/// </summary>
/// <param>No parameters.</param>
/// <returns>Nothing.</returns>
    void user_main_menu();
/// <summary>
/// The function that prints the user adoption menu.
/// </summary>
/// <param>No parameters.</param>
/// <returns>Nothing.</returns>
    void user_adoption_menu();
};


