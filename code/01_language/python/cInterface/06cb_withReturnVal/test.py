import ctypes


def test_callback():
    print("hello world")
    return -1


clib = ctypes.cdll.LoadLibrary("./libtarget.so")
func_hello_world = clib.hello_world

functype = ctypes.CFUNCTYPE(ctypes.c_int)  # 返回值int，无参数
c_callback_python = functype(test_callback)

func_hello_world.restype = ctypes.c_int
func_hello_world.argtype = ctypes.CFUNCTYPE

func_hello_world(c_callback_python)

'''
python中调用C的函数，并为C的函数注册回调函数的简单示例

当有返回值时的示例
'''
