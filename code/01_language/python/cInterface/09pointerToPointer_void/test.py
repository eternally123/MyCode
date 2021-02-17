import ctypes

test = ctypes.cdll.LoadLibrary("./libtarget.so")

func_hello_world = test.hello_world
func_hello_world.argtype = ctypes.POINTER(ctypes.c_void_p)
func_hello_world.restype = ctypes.POINTER(ctypes.POINTER(ctypes.c_int))

num = 3
print(type(num))
address = ctypes.c_void_p(id(num))
param = ctypes.pointer(address)
ret = func_hello_world(param)

print(type(ret))
print(ret.contents.contents.value)

'''
可能void_p用途在于为两个C函数传递数据？
没有看到python构造void*或void**类型数据传递给C
'''
