#!/usr/local/bin/python
# -*- coding: utf-8 -*-

import random
from constants import *
from sets import Set

def generateFile(index):
    filename = 'random.in'
    f = open(filename, 'w');

    D = 500
    print >>f, D

    for _ in xrange(D):
        N = random.randint(N_MIN, N_MAX)
        M = random.randint(N+1, M_MAX)
        A = random.randint(A_MIN, A_MAX)
        print >>f, N, M, A

        # 自分の成績を入れる位置
        idx = random.randint(1, M)
        nums = Set([A])
        for i in xrange(M):
            S = A
            if i+1 != idx:
                while True:
                    S = random.randint(S_MIN,S_MAX)
                    if S not in nums:
                        break

            nums.add(S)
            if i == M-1:
                print >>f, S
            else:
                print >>f, S,

def main():
  for index in xrange(10):
      generateFile(index)

if __name__ == '__main__':
    main()
