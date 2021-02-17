import ctypes

test = ctypes.cdll.LoadLibrary("./libtarget.so")

func_hello_world = test.hello_world
func_hello_world.argtype = ctypes.POINTER(ctypes.POINTER(ctypes.c_int))
func_hello_world.restype = ctypes.POINTER(ctypes.POINTER(ctypes.c_int))

num = ctypes.c_int(10)
param = ctypes.pointer(ctypes.pointer(num))
ret = func_hello_world(param)

print(type(ret))
print(ret.contents.contents.value)
