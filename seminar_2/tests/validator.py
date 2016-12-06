#!/usr/bin/python

import os
import sys
from constants import *
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../lib')
from checker import Checker

def main():
    ch = Checker()

    d = ch.readInt()
    for _ in xrange(d):
        n,m,a = ch.readInts(3)
        ch.checkRange(n, N_MIN, N_MAX, 'N')
        ch.checkRange(m, M_MIN, M_MAX, 'M')
        ch.checkRange(a, A_MIN, A_MAX, 'A')

        s = ch.readInts(m)
        for v in s:
            ch.checkRange(v, S_MIN, S_MAX, 'S')

if __name__ == '__main__':
    main()
