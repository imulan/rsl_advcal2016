#!/usr/bin/python
# -*- coding: utf-8 -*-

import random
from constants import *

def generateFile(index):
    filename = 'random%d.in' % index
    f = open(filename, 'w');

    D = 200
    print >>f, D

    for _ in xrange(D):
        N = random.randint(N_MIN[index], N_MAX[index])
        print >>f, N

        for i in xrange(N):
            M = random.randint(M_MIN[index], M_MAX[index])
            if i == N-1:
                print >>f, M
            else:
                print >>f, M,

def main():
  for index in xrange(2):
      generateFile(index)

if __name__ == '__main__':
    main()
