import ctypes

test = ctypes.cdll.LoadLibrary("./libtarget.so")

func_hello_world = test.hello_world
func_hello_world.argtype = ctypes.POINTER(ctypes.c_int)  # 多个传入参数如下
# func_hello_world.argtypes = (ctypes.POINTER(ctypes.c_int),ctypes.POINTER(ctypes.c_int))
func_hello_world.restype = ctypes.POINTER(ctypes.c_int)

num1 = ctypes.c_int(10)       # 构造指针1
para1 = ctypes.pointer(num1)  # 构造指针2
ret = func_hello_world(para1)
print(type(ret))           # <class '__main__.LP_c_int'>
print(ret.contents)        # c_int(10)
print(ret.contents.value)  # 10
