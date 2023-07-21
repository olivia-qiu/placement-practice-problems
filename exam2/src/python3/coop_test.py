import os
import sys
from typing import List, Dict
from ingredient import Ingredient
from order import Order
from coop import mk_coop_order

sys.path.insert(0, os.getcwd())

import test_helpers as th


class CoopTest:
    '''
    Class for testing the coop problem.
    '''

    def __init__(self) -> None:
        '''
        Initialize a CoopTest object.
        '''
        family_ingredients = []
        recipe_ingredients = []
        orders = []

    def run_test(self, file: str, verbose: bool) -> bool:
        '''
        Run the test for the given file.
        '''
        family_ingredients = []
        recipe_ingredients = []
        orders = []

        try:
            with open(file) as f:
                lines = f.readlines()

                header = lines[0].strip().split()
                num_family_lines = int(header[0])
                num_recipe_lines = int(header[1])
                num_order_lines = int(header[2])

                self.family_ingredients = self.load_ingredients(lines,
                                                                num_family_lines,
                                                                1)
                self.recipe_ingredients = self.load_ingredients(lines,
                                                                num_recipe_lines,
                                                                1 + num_family_lines)
                self.orders = self.load_orders(lines, num_order_lines,
                                               1 + num_family_lines + num_recipe_lines)
        except FileNotFoundError:
            if verbose:
                print(f'File {file} not found.')
            return False
        except ValueError:
            if verbose:
                print(f'File {file} has invalid format.')
            return False
        except Exception as e:
            if verbose:
                print(f'Unexpected error: {e}')
            return False

        # Running the student's code
        actual = None
        try:
            actual = mk_coop_order(self.family_ingredients,
                                   self.recipe_ingredients,
                                   self.orders)
        except Exception as e:
            if verbose:
                print(f'Unexpected error: {e}')
            return False

        # Checking against the expected result
        return self.check_result(file.replace('.in', '.ans'), actual, verbose)

    def load_ingredients(self, lines: List[str], num_lines: int, index: int) -> List[Ingredient]:
        '''
        Load the ingredients from the given lines.
        '''
        ingredients = []

        for index, line in enumerate(lines[index:index + num_lines]):
            data = line.strip().split()
            ingredient, name, amount = data
            ingredients.append(Ingredient(name, ingredient, int(amount)))

        return ingredients

    def load_orders(self, lines: List[str], num_lines: int, index: int) -> List[Order]:
        '''
        Load the orders from the given lines.
        '''
        orders = []

        for index, line in enumerate(lines[index:index + num_lines]):
            data = line.strip().split()
            family, recipe = data
            orders.append(Order(family, recipe))

        return orders

    def check_result(self, file: str, actual: Dict[str, int], verbose: bool) -> bool:
        '''
        Check the result for the given file.
        '''
        try:
            with open(file) as f:
                lines = f.readlines()

                for line in lines:
                    data = line.strip().split()
                    name, amount = data

                    # Check that actual has the same keys as expected
                    if name not in actual:
                        return False
                    # Check that actual has the same values as expected
                    elif actual[name] != int(amount):
                        return False
        except FileNotFoundError:
            if verbose:
                print(f'File {file} not found.')
            return False
        except ValueError:
            if verbose:
                print(f'File {file} has invalid format.')
            return False
        except Exception as e:
            if verbose:
                print(f'Unexpected error: {e}')
            return False

        # Check for additional keys in actual
        return (len(actual) == len(lines))


if __name__ == '__main__':
    # Initialize argument parser
    args = th.create_parser('Test the cold solution.').parse_args()

    # Figure out if we're testing all files or just one, if we're testing all
    # files, get the list of files to test
    if args.test_dir is not None:
        test_files = th.get_test_files(args.test_dir)

        for test_file in test_files:
            coop_test = CoopTest()

            test_result = coop_test.run_test(test_file, True)
            if test_result:
                print(f'Passed {test_file}')
            else:
                print(f'Failed {test_file}')

    elif args.test_file is not None:
        test_file = args.test_file
        coop_test = CoopTest()

        test_result = coop_test.run_test(test_file, True)
        if test_result:
            print('PASSED')
            sys.exit(42)
        else:
            print('FAILED')
            sys.exit(0)

    else:
        raise ValueError('Must provide either a test file or a test directory.')