import ctypes

library = ctypes.CDLL('./lib.so')

library.connect()

x = library.DFT(1, 2)

print(x)