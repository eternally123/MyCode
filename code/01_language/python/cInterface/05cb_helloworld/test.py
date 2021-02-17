import ctypes


def test_callback():
    print("hello world")
    return


clib = ctypes.cdll.LoadLibrary("./libtarget.so")
func_hello_world = clib.hello_world


func_hello_world.restype = ctypes.c_int
func_hello_world.argtype = ctypes.CFUNCTYPE

functype = ctypes.CFUNCTYPE(None)  # 返回值int，无参数
c_callback_python = functype(test_callback)
# c_callback_python = functype(0)
func_hello_world(c_callback_python)

'''
python中调用C的函数，并为C的函数注册回调函数的简单示例

编写过程：
1.python中编写回调函数test_callback
2.创建函数指针对象
    2.1通过ctypes.FUNCTYPE创建回调函数对象（即包括返回值类型与传入参数类型）
    2.2通过2.1创建的回调函数对象与回调函数生成函数指针
3.为C函数指明参数与返回值
4.调用C函数，传入2生成的函数指针
'''
