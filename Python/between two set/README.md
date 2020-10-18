# Between Two Sets

## Description

You will be given two arrays of integers and asked to determine all integers that satisfy the following two conditions:
1. The elements of the first array are all factors of the integer being considered
2. The integer being considered is a factor of all elements of the second array

## Input Format

The first line contains two space-separated integers, `n` and `m`, the number of elements in array `a` and the number of elements in array `b`.
The second line contains `n` distinct space-separated integers describing `a[i]` where `0 <= i < n`.
The third line contains `m` distinct space-separated integers describing `b[j]` where `0 <= j < m`.

## Output Format

Print the number of integers that are considered to be between `a` and `b`.