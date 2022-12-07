#!/usr/bin/python3
"""Task 0"""


def canUnlockAll(boxes):
    """method that determines if all the boxes can be opened"""
    keys = [*range(len(boxes))]
    unlock_boxes = [0]
    for key, box in zip(keys, boxes):
        if not box:
            continue
        for k in box:
            if k < len(boxes) and k not in unlock_boxes and k != key:
                unlock_boxes.append(k)
    if len(unlock_boxes) == len(boxes):
        return True
    return False
