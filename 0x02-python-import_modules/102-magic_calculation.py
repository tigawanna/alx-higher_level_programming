#!/usr/bin/python3


def magic_calculation(a, b):
    """Magic calculator."""
    from magic_calculation_102 import add, sub

    if a < b:
        c = add(a, b)
        for count in range(4, 6):
            c = add(c, count)
        return (c)
    else:
        return(sub(a, b))
