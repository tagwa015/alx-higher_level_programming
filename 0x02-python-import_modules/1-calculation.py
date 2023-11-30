#!/usr/bin/python3
a = 10
b = 5

from calculator_1 import add, subtract, multiply, divide

addition_result = add(a, b)
subtraction_result = subtract(a, b)
multiplication_result = multiply(a, b)
division_result = divide(a, b)

print("Addition of {} and {} = {}".format(a, b, addition_result))
print("Subtraction of {} and {} = {}".format(a, b, subtraction_result))
print("Multiplication of {} and {} = {}".format(a, b, multiplication_result))
print("Division of {} and {} = {}".format(a, b, division_result))
