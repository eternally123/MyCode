from ctypes import *
test = cdll.LoadLibrary("./libtarget.so")
test.hello_world.restype = c_char # 指定返回值为char
c = test.hello_world(48) # 调用函数，传入参数48
print(type(c))
print(c)