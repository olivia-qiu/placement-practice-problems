'''
Distribution file of the itshotitscold problem.
'''

from typing import List
from typing import Tuple

def itshotitscold(temperatures: List[int]) -> Tuple[int, int, int]:
    '''
    This function takes a list of temperatures. It returns a tuple of
    three integers: the number of times the temperature went down, the
    number of times the temperature remained the same, and the number
    of times the temperature went up.

    Arguments:
        temperatures: a list of integers representing temperatures.

    Returns:
        A tuple of three integers representing the number of times the 
        temperature went down, the number of times the temperature remained the 
        same, and the number of times the temperature went up.

    '''
    lower = None
    equal = None
    higher = None
    for n in range len(temperatures)-1:
        if temperatures[n+1]<temperatures[n]:
            lower += 1
        if temperatures[n+1] == temperatures[n]
            equal +=1 
        if temperatures[n+1]<temperatures[n]:
            higher +=1 
    return lower,equal,higher
            
