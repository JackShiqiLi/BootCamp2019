# -*- coding: utf-8 -*-
"""
Created on Tue Jul  2 15:02:54 2019

@author: jiutian
"""

import sys
import random
import time
import box
import numpy as np
from itertools import combinations

def isvalid_1_dice(roll, remaining):
    '''
    Check to see whether or not a roll is valid. That is, check if there
    exists a combination of the entries of 'remaining' that sum up to
    'roll'.

    Parameters:
        roll (int): The value of a dice roll, between 2 and 12
                    (inclusive).
        remaining (list): The list of the numbers that still need to be
                          removed before the box can be shut.

    Returns:
        True if the roll is valid.
        False if the roll is invalid.
    '''
    if roll not in range(1, 7):
        return False
    for i in range(1, len(remaining) + 1):
        if any([sum(combo) == roll for combo in combinations(remaining, i)]):
            return True
    return False

if len(sys.argv) == 3: #only start if there are two extra arguments
    username = sys.argv[1]
    timelimit = int(sys.argv[2])
    remaining_numbers = list(range(10))
    starting_time = time.time()
    remaining_time = timelimit
    
    while remaining_time > 0:
        
        while np.sum(remaining_numbers) > 6:
            print('Numbers left: %s' % remaining_numbers)
            roll = random.randint(1, 6) + random.randint(1, 6)
            
            if box.isvalid(roll, remaining_numbers):
                print('roll: %0d' % roll)
                print('Seconds left: %s' % remaining_time)
                eliminate_numbers = input('Numbers to eliminate: ')
                try: 
                    number_list = [int(number) for number in eliminate_numbers if number != ' ']
                except ValueError:
                    print('invalid input \n')
                if np.sum(number_list) == roll:
                    for number in number_list:
                        remaining_numbers.remove(number)
                else:
                    print('invalid input \n')
                current_time = time.time()
                time_passed = current_time - starting_time
                remaining_time = timelimit - time_passed
                print('\n')
                
            else:
                print('roll: %0d' % roll)
                print('Game over!')
                print('\n')
                break
                
        while 0 < np.sum(remaining_numbers) < 6:
            print('Numbers left: %s' % remaining_numbers)
            roll = random.randint(1, 6)
            if isvalid_1_dice(roll, remaining_numbers):
                print('roll: %0d' % roll)
                print('Seconds left: %s' % remaining_time)
                eliminate_numbers = input('Numbers to eliminate: ')
                try: 
                    number_list = [int(number) for number in eliminate_numbers if number != ' ']
                except ValueError:
                    print('invalid input \n \n')
                if np.sum(number_list) == roll:
                    for number in number_list:
                        remaining_numbers.remove(number)
                else:
                    print('invalid input \n \n')
                current_time = time.time()
                time_passed = current_time - starting_time
                remaining_time = timelimit - time_passed
                print('\n')
            else:
                print('roll: %0d' % roll)
                print('Game over!')
                print('\n')
                break
        
        if len(remaining_numbers) == 0:
            print('Score for player %s： 0 points \n\
Time Played: %2f seconds \n\
Congratulations!! You shut the box!' % (username, time_passed))
            break
    
        elif len(remaining_numbers) > 0:
            print('Score for player %s： %0d points \n\
Time Played: %2f seconds \n\
Better luck next time >:)' % (username, np.sum(remaining_numbers), time_passed))
            break
                
    if remaining_time < 0:    
        print('Game over!')
        print('\n')
        print('Score for player %s： %d points \n\
Time Played: %2f seconds \n\
Better luck next time >:)' % (username, np.sum(remaining_numbers), time_passed))
        
            
            