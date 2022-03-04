#include <vector>
#include <string>
#include "validators.h"

bool Validator::valid(int id, const std::string &breed, const std::string &name, int age, const std::string &photograph)
{
    bool ok = true;
    if (id<0)
        ok = false;
    if(breed.empty())
        ok = false;
    if(name.empty())
        ok = false;
    if(age<0)
        ok = false;
    if(photograph.empty())
        ok = false;
    return ok;
}