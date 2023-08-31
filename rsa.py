#!/usr/bin/python3

import ctypes
import sys

# Load the shared library
prime_factors_lib = ctypes.CDLL('./prime_factors.so')

# Define the argument and return types of the function
prime_factors_lib.find_prime_factors.argtypes = [ctypes.c_char_p]
prime_factors_lib.find_prime_factors.restype = None

def find_prime_factors():
     
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        exit()

    try:
        with open(sys.argv[1], 'r') as f:
            num_str = f.readline().strip()
            prime_factors_lib.find_prime_factors(num_str.encode('utf-8'))
    except FileNotFoundError:
        print("File not found")
        exit()
        
if __name__ == '__main__':
    find_prime_factors()