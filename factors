import ctypes
import sys

# Load the shared library containing the find_factors function
find_factors_lib = ctypes.CDLL('./find_factors_gmp.so')

# Define the argument type for the find_factors function
find_factors_lib.find_factors.argtypes = [ctypes.c_char_p]
find_factors_lib.find_factors.restype = None

def find_factors():
 
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        exit()

    try:
        with open(sys.argv[1], 'r') as f:
            lines = f.readlines()
    except FileNotFoundError:
        print("File not found")
        exit()

    for line in lines:
        N = line.encode() # Convert Python string to C-style string
        find_factors_lib.find_factors(N)

if __name__ == "__main__":
    find_factors()
