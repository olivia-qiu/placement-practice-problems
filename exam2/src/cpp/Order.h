#ifndef _Order_
#define _Order_
#include <string>

class Order {
public:

std::string family_name;
std::string recipe_name;

Order (std::string const &family, std::string const &recipe)
: family_name(family), recipe_name(recipe) {}

std::string to_string() {
    return "order: " + family_name + " " + recipe_name;
}

};

#endif
