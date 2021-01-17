from ctypes import *
test = cdll.LoadLibrary("./libtarget.so")
test.hello_world()