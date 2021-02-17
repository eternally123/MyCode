import ctypes

ctypes.CDLL("../libtarget1.so", ctypes.RTLD_GLOBAL)
clib = ctypes.cdll.LoadLibrary("./libtarget2.so")
func_call_add = clib.call_add

func_call_add.argtype = (ctypes.c_int, ctypes.c_int)
func_call_add.restype = ctypes.c_int

ret = func_call_add(1, 2)
print(ret)

'''
# 当加载的so依赖于多个其他的so时，需要在一开始通过ctypes.CDLL将依赖的库全部加载
'''
