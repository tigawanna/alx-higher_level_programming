#!/usr/bin/python3


def uniq_add(my_list=[]):
    result = 0
    for uniq in set(my_list):
        result = uniq + result
    return result
