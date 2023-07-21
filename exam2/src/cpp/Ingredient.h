#ifndef _Ingredient_
#define _Ingredient_
#include <string>

/**
 * Ingredient: represent an ingrediant in a family's pantry, an
 *   ingredient needed for a recipe, or an ingredient in the
 *   coop's ledger.
 **/

class Ingredient {
public:

std::string name; // the name of the ingredient
std::string key; // a family name or recipe name
int amount;

Ingredient (
    std::string const &ingredient_name,
    std::string const &_key,
    int const &_amount)
: name(ingredient_name), key(_key), amount(_amount) {}

std::string to_string() {
    return "item: " + key + " " + name + " " + std::to_string(amount);
}

};

#endif