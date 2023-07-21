#ifndef _Coop_
#define _Coop_

#include "Ingredient.h"
#include "Order.h"
#include <string>
#include <vector>
#include <unordered_map>

std::unordered_map<std::string, int> mk_coop_order(
    std::vector<Ingredient*> const &pantry_items,
    std::vector<Ingredient*> const &recipe_items,
    std::vector<Order*> const &orders
);

#endif
