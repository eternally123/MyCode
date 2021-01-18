import ctypes

test = ctypes.cdll.LoadLibrary("./libtarget.so")

func_hello_world = test.hello_world
func_hello_world.argtype = ctypes.c_int  # 指定传入参数为int(如果多个参数用argtypes)
func_hello_world.restype = ctypes.c_char  # 指定返回值为char

c = func_hello_world(48)  # 调用函数，传入参数48

print(type(c))
print(c)
