import ctypes
import os

path = os.getcwd()
clibrary = ctypes.CDLL(os.path.join(path, 'libfactorize.so'))

clibrary.factorize.restype = ctypes.POINTER(ctypes.c_uint64)
clibrary.factorize.argtypes = [ctypes.c_uint64]