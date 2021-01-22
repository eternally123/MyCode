# !/usr/bin/python3

import datetime
import ctypes
import os


def myadd(a, b):
    print(datetime.date.ctime)
    return a+b


def mychello():
    clib = ctypes.cdll.LoadLibrary(
        os.path.abspath(os.path.dirname(__file__))+"/clib/libtarget.so")
    func_helloworld = clib.hello_world
    func_helloworld()
    return
