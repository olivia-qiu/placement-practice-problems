'''
Order class module for the coop problem.
'''

class Order:
    '''
    Represents a family's order, which is composed of a family name and a recipe
    name.
    '''
    def __init__(self, family: str, recipe: str) -> None:
        '''
        Initialize an Order object.

        Arguments:
            family: The family name.
            recipe: The recipe name.

        Returns:
            None
        '''
        self.family = family
        self.recipe = recipe

    def to_string(self) -> str:
        '''
        Returns a string representation of the Order object.

        Arguments:
            None

        Returns:
            A string representation of the Order object.
        '''
        return f'order: {self._family} {self._recipe}'