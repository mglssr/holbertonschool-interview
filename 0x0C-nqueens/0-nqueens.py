#!/usr/bin/python3
import sys


def print_board(board):
    """ print queens position on board """
    new_list = []
    for i, row in enumerate(board):
        value = []
        for j, column in enumerate(row):
            if column == 1:
                value.append(i)
                value.append(j)
        new_list.append(value)
    print(new_list)


def isSafe(board, row, column, number):
    """ isSafe """
    # Check this row in the left side
    for i in range(column):
        if board[row][i] == 1:
            return False
    # Check upper diagonal on left side
    for i, j in zip(range(row, -1, -1), range(column, -1, -1)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row, number, 1), range(column, -1, -1)):
        if board[i][j] == 1:
            return False
    return True


def solveNQ(board, column, number):
    """ Auxiliar method to find the posibilities of answer """
    if (column == number):
        print_board(board)
        return True
    res = False
    for i in range(number):
        if (isSafe(board, i, column, number)):
            board[i][column] = 1
            res = solveNQ(board, column + 1, number) or res
            board[i][column] = 0  # BACKTRACK

    return res


def solve(number):
    """ Find all the posibilities if exists """
    board = [[0 for i in range(number)]for i in range(number)]
    if not solveNQ(board, 0, number):
        return False
    return True


def validate(args):
    """ Validate the input data to verify it """
    if (len(args) == 2):
        try:
            number = int(args[1])
        except Exception:
            print("N must be a number")
            exit(1)
        if number < 4:
            print("N must be at least 4")
            exit(1)
        return number
    else:
        print("Usage: nqueens N")
        exit(1)


if __name__ == "__main__":
    """ Main method to execute the application """
    number = validate(sys.argv)
    solve(number)
