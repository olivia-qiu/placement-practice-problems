'''
Ingredient class module for the coop problem.
'''

class Ingredient:
    '''
    Ingredient: represent an ingredient in a family's pantry, an
    ingredient needed for a recipe, or an ingredient in the
    coop's ledger.
    '''
    def __init__(self, name: str, key: str, amount: int) -> None:
        '''
        Initialize an Ingredient object.

        Arguments:
            name: The name of the ingredient.
            key: The family or recipe key for the ingredient.
            amount: The amount of the ingredient.

        Returns:
            None
        '''
        self.name = name
        self.key = key
        self.amount = amount

    def to_string(self) -> str:
        '''
        Returns a string representation of the Ingredient object.

        Arguments:
            None

        Returns:
            A string representation of the Ingredient object.
        '''
        return f'item: {self._name}, key: {self._key}, amount: {self._amount}'