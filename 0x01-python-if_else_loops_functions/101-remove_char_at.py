#!/usr/bin/python3
def remove_char_at(string, n):
    new_string = ""
    for i, char in enumerate(string):
        if i != n:
            new_string += char
    return new_string
