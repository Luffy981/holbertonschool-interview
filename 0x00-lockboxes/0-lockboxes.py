#!/usr/bin/python3
""" Can un lock all """
import sys
sys.setrecursionlimit(2000)


def setUnlock(boxes, unlocked, index=0):
    """ Set the lock on all boxes """
    if index >= len(boxes) or unlocked[index]:
        return
    unlocked[index] = True
    keys = boxes[index]
    for key in keys:
        setUnlock(boxes, unlocked, key)


def canUnlockAll(boxes):
    """ Can un lock all """
    from functools import reduce

    if type(boxes) is not list or len(boxes) == 0:
        return False

    unlocked = list(map(lambda _: False, range(len(boxes))))
    setUnlock(boxes, unlocked)
    return reduce(lambda acum, value: acum and value, unlocked)
