import math
import os
import random
import re
import sys

def getTotalX(a, b):
    minInt = max(a)
    maxInt = min(b)
    numberBetween = list(range(minInt,maxInt+1))
    tmpFactor = []
    factor = []

    for number in numberBetween:
        isFactor = False
        for elmA in a:
            if number % elmA != 0:
                isFactor = False
                break
            else:
                isFactor = True
        if isFactor:
            tmpFactor.append(number)
        

    for tmp in tmpFactor:
        isFactor = False
        for elmB in b:
            if elmB % tmp != 0 :
                isFactor = False
                break
            else : 
                isFactor = True
        if isFactor:
            factor.append(tmp)
    
    return len(factor)

if __name__ == '__main__':

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    brr = list(map(int, input().rstrip().split()))

    total = getTotalX(arr, brr)

    print(total)