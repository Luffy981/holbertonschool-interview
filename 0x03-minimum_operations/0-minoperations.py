#!/usr/bin/python3
"""
Module contains function for finding
minimum operations needing to get n
characters in a string using only copy and
paste opperations.
"""


def get_widest_factors(x):

    if x == 1:
        return None, None

    for i in range(2, x + 1):
        if x % i == 0:
            return i, int(x/i)

    return x, 1


def minOperations(n):
    """
    Finds minimum operations needing to get n
    characters in a string using only copy and
    paste opperations.

    Args:
        n: Length of string objective.

    Return:
        Maximum operations to get string of length n.
    """

    if type(n) is not int or n <= 1:
        return 0

    operations = []

    while n is not None:
        ops, n = get_widest_factors(n)

        if ops is not None:
            operations.append(ops)

    return sum(operations)
