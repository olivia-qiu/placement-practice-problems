#include "TestHelpers.h"
#include "Coop.h"
#include "Ingredient.h"
#include "Order.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <assert.h>
#include <unordered_map>

namespace test {

std::unordered_map<std::string, int> get_result(std::string& f) {
    std::string resultsFileName = TestHelpers::getResultsFile(f);
    std::ifstream ifs(resultsFileName);
    std::unordered_map<std::string, int> res;

    if (ifs) {
        while (ifs) {
            std::string line;
            std::getline(ifs, line);
            std::istringstream iss(line);
            std::string ingredient;
            int amount = -1;
            iss >> ingredient >> amount;
            if (amount != -1) {
                res[ingredient] = amount;
            }
        }
    } else {
        std::cout << "Results file not found: " << resultsFileName << std::endl;
        exit(1);
    }
    return res;
 }

void get_data(
    std::string& f,
    std::vector<Ingredient*>& family_ingredients,
    std::vector<Ingredient*>& recipe_ingredients,
    std::vector<Order*>& orders)
{
    std::string dataFileName = TestHelpers::getDataFile(f);
    std::vector<std::vector<int>> pieces;
    int num_family = -1, num_recipe = -1, num_orders = -1;

    std::ifstream ifs(dataFileName);
    if (ifs) {
        ifs >> num_family >> num_recipe >> num_orders;
        if (num_family == -1 || num_recipe == -1 || num_orders == -1) {
            std::cout << "Format error" << std::endl;
            return;
        }

        // load faimly ingredients of the form: name ingredient amount
        for (size_t i = 0; i < num_family; i++) {
            std::string name, ingredient;
            int amount;
            ifs >> name >> ingredient >> amount;
            family_ingredients.push_back(new Ingredient(ingredient, name, amount));
        }

        // load recipe ingredients of the form: name ingredient amount
        for (size_t i = 0; i < num_recipe; i++) {
            std::string name, ingredient;
            int amount;
            ifs >> name >> ingredient >> amount;
            recipe_ingredients.push_back(new Ingredient(ingredient, name, amount));
        }

        // load orders form: family_name recipe_name
        for (size_t i = 0; i < num_orders; i++) {
            std::string family_name, recipe_name;
            ifs >> family_name >> recipe_name;
            orders.push_back(new Order(family_name, recipe_name));
        }

    } else {
        std::cout << dataFileName << " failed to be read" << std::endl;;
        return;
    }

    return ;
}


bool runTest(std::string f) {
    std::vector<Ingredient*> family_ingredients;
    std::vector<Ingredient*> recipe_ingredients;
    std::vector<Order*> orders;

    get_data(f, family_ingredients, recipe_ingredients, orders);
    auto actual = mk_coop_order(family_ingredients, recipe_ingredients, orders);
    auto expected = get_result(f);

    if (actual.size() != expected.size()) {
        std::cout << "Failed actual number of result and expected number of result do not match" << "\n";
        std::cout << "    actual number of result is " << actual.size() << "\n";
        std::cout << "    expected number of result is " << expected.size() << "\n";
	    return false;
    }

    std::unordered_map<std::string, int>::iterator pos;
    for (pos = actual.begin(); pos != actual.end(); pos++) {
        std::string ingredient = pos->first;
        if (actual[ingredient] != expected[ingredient]) {
            std::cout << "Failed actual result and expected result do not match for item " << ingredient <<" \n";
            std::cout << "    actual is " << actual[ingredient] << "\n";
            std::cout << "    expected is " << expected[ingredient] << "\n";
            return false;
        }
    }

    return true;
}

} // namespace test

int main (int argc, char* argv[])
{
    std::vector<std::string> files = TestHelpers::getFiles(argc, argv);
    if (files.size() == 0) {
        std::cout << "no test file found";
        exit(1);
    }

    int count = 0;
    for (size_t i = 0; i < files.size(); ++i) {
        std::string f = files[i];
        std::cout << "Test " << f << ": ";
        if (test::runTest(f)) {
            std::cout << "PASSED\n";
            count++;
        } else {
            std::cout << "FAILED\n";
        }
    }

    if (count == files.size()) {
        return 42;
    } else {
        return 0;
    }

}
