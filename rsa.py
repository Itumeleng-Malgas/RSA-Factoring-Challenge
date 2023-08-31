#!/usr/bin/python3

import ctypes
import sys

# Load the shared library
prime_factors_lib = ctypes.CDLL('./prime_factors.so')

# Define the argument and return types of the function
prime_factors_lib.find_prime_factors.argtypes = [ctypes.c_char_p]
prime_factors_lib.find_prime_factors.restype = None

def find_prime_factors():
    with open(sys.argv[1]) as f:
        num_str = f.readline().strip()
        prime_factors_lib.find_prime_factors(num_str.encode('utf-8'))
            
if __name__ == '__main__':
    find_prime_factors()