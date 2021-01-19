import ctypes


def func():
    clib = ctypes.cdll.LoadLibrary("./libtarget.so")

    func_get = clib.get
    func_get.restype = ctypes.c_void_p

    func_print = clib.print
    func_print.argtype = ctypes.c_void_p

    ret = func_get()
    print(ret)
    func_print(ret)
    print(ret)


'''
可以看到，正常运作
且ret的值就是void*，和C中打印的地址的值一样。
（C中print函数打印的num地址为23138720，ret的值也为23138720）
'''
if __name__ == "__main__":
    func()
