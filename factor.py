#!/usr/bin/python3
import sys

if len(sys.argv) != 2:
    sys.exit(1)

with open(sys.argv[1]) as f:
    for line in f.readlines():
        n = int(line)
        for i in range(2, n//2):
            if n % i == 0:
                print("{}={}*{}".format(n, i, n//i))
                break
