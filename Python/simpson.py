import math
from sympy import var
from sympy import sympify


def func(x):
    res = expr.subs(varx, x)
    return res


def simpsons(a, b, n):
    h = (b - a) / n

    hasil = 0
    i = 0
    while i <= n:
        x = a + i * h
        fx = func(x)
        if i == 0 or i == n:
            hasil += fx
        elif i % 2 == 0:
            hasil += 2 * fx
        else:
            hasil += 4 * fx
        i += 1
    return hasil * (h / 3)


varx = var('x')
inputfunction = input("Input Function: ")
expr = sympify(inputfunction)

bawah = input("Input lower limit: ")
bawah = float(bawah)

atas = input("Input upper limit: ")
atas = float(atas)

pembagi = input("Input number of N: ")
pembagi = float(pembagi)

print(simpsons(bawah, atas, pembagi))
