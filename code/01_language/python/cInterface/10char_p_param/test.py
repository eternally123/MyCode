import ctypes

clib = ctypes.cdll.LoadLibrary("./libtarget.so")
func_hello_world = clib.hello_world

func_hello_world.argtype = ctypes.c_char_p

# msg = b"python str"
# param = ctypes.c_char_p(msg)
msg = "python str"
# param = ctypes.c_char_p(bytes(msg, encoding="ascii"))
param = ctypes.c_char_p(bytes(msg, encoding="utf-8"))
func_hello_world(param)
