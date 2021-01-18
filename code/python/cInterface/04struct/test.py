import ctypes
test = ctypes.cdll.LoadLibrary("./libtarget.so")


class test_struct(ctypes.Structure):  # 通过创建继承自Structure的类支持结构体
    _fields_ = [('ptr', ctypes.c_char_p),
                ('c', ctypes.c_float),
                ('array', ctypes.c_char * 10)]


func_hello_world = test.hello_world
func_hello_world.restype = ctypes.POINTER(test_struct)
func_hello_world.argtype = ctypes.POINTER(test_struct)

struct = test_struct(c=10)
ret_struct = func_hello_world(ctypes.pointer(struct))

print(ret_struct.contents)
print()
print(type(ret_struct.contents.ptr))
print(ret_struct.contents.ptr)
print()
print(type(ret_struct.contents.c))
print(ret_struct.contents.c)
print()
print(type(ret_struct.contents.array))
print(ret_struct.contents.array)
