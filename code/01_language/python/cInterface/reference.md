## 博客链接
```
https://www.docs4dev.com/docs/zh/python/3.7.2rc1/all/library-ctypes.html # 官方文档
https://www.cnblogs.com/downey-blog/p/10483342.html # 简单示例
https://python3-cookbook.readthedocs.io/zh_CN/latest/c15/p01_access_ccode_using_ctypes.html # 官方文档
https://blog.csdn.net/abc15766228491/article/details/78883781 # 返回值为指针
https://blog.csdn.net/sweibd/article/details/52679213 # 回调函数
```
## 代码示例使用
```
（一般都是一个C文件，一个python文件）
1.对C文件，制作动态库：
gcc -fPIC --shared target.c -o libtarget.so
2.运行python文件，即可实现对C的调用
```