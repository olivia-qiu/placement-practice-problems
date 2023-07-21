'''
Co-op module for the coop problem.
'''

from typing import List, Dict
from ingredient import Ingredient
from order import Order


def mk_coop_order(pantry_items: List[Ingredient],
                  recipe_items: List[Ingredient],
                  orders: List[Order]) -> Dict[str, int]:
    '''
    Takes in a list of pantry items, a list of recipe items, and a list of
    orders and returns a dictionary of the items to be ordered from the
    Co-op and the quantity of each item to be ordered.

    Arguments:
        pantry_items: A list of Ingredient objects representing the items
            currently in the pantry.
        recipe_items: A list of Ingredient objects representing the items
            needed to make the recipe.
        orders: A list of Order objects representing the orders that have
            been placed.

    Returns:
        A dictionary of the items to be ordered from the Co-op and the
        quantity of each item to be ordered.
    '''
    # TODO: Implement this function
    return None
