#!/usr/bin/python3
""" script that reads stdin line by line and computes metrics """

import sys


st_codes = {"200": 0, "301": 0, "400": 0, "401": 0,
            "403": 0, "404": 0, "405": 0, "500": 0}

file_size = 0


def print_stats():
    """ print stats """
    print("File size: {}".format(file_size))
    for key in sorted(st_codes.keys()):
        if st_codes[key]:
            print("{}: {}".format(key, st_codes[key]))


if __name__ == "__main__":
    count = 0
    try:
        for line in sys.stdin:
            try:
                items = line.split()
                file_size += int(items[-1])
                if items[-2] in st_codes:
                    st_codes[items[-2]] += 1
            except:
                pass
            if count == 9:
                print_stats()
                count = -1
            count += 1
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
