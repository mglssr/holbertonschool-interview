#!/usr/bin/python3
""" Lockboxes """


def canUnlockAll(boxes):
    """ Method that determines if all the boxes can be opened """
    Nboxes = len(boxes)
    closed_boxes = [0]
    checked_boxes = set(closed_boxes)

    if Nboxes <= 1:
        return True

    while closed_boxes:
        box = closed_boxes.pop()
        for key in boxes[box]:
            if key not in checked_boxes and key < Nboxes:
                closed_boxes.append(key)
                checked_boxes.add(key)

    if len(checked_boxes) == Nboxes:
        return True
    else:
        return False
