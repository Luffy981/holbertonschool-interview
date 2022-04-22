#!/usr/bin/python3
"""unlock boxes"""


def canUnlockAll(boxes):
    """unlocking!"""
    unlocked = boxes[0]
    for box_id, keys in enumerate(boxes):
        if not keys:
            continue
        for key in keys:
            if key < len(boxes) and key not in unlocked and key != box_id:
                unlocked.append(key)
    if len(unlocked) == len(boxes):
        return True
    return False
