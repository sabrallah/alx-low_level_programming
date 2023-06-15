#!/usr/bin/python3

def is_palindrome(n):
    return str(n) == str(n)[::-1]


num_digits = int(input("Enter the number of digits: "))


lower_limit = 10 ** (num_digits - 1)
upper_limit = 10 ** num_digits


largest_palindrome = 0


for i in range(lower_limit, upper_limit):
    for j in range(lower_limit, upper_limit):
        product = i * j
        if is_palindrome(product) and product > largest_palindrome:
            largest_palindrome = product


with open("102-result", "w") as file:
    file.write(str(largest_palindrome))
