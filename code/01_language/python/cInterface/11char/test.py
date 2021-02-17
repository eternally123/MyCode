import ctypes

clib = ctypes.cdll.LoadLibrary("./libtarget.so")
func_hello_world = clib.hello_world

func_hello_world.argtype = ctypes.c_char_p

buf = b"\0"*100
param1 = ctypes.c_char_p(buf)
param2 = ctypes.c_int(100)

func_hello_world(param1, param2)
print(buf)
