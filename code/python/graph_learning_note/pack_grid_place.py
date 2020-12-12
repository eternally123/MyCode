import tkinter as tk

# 定义根窗口
window = tk.Tk()  # 一个根窗口
window.title("my window")  # 窗口名
window.geometry('800x800')  # 窗口长宽

# 方法二：
# for i in range(4):
#     for j in range(3):
#         tk.Label(window, text=1).grid(row=i, column=j, ipady=10)  # ipad pad 会展开一点

# 方法一：
# tk.Label(window, text=1).pack(side='top')
# tk.Label(window, text=1).pack(side='bottom')
# tk.Label(window, text=1).pack(side='left')
# tk.Label(window, text=1).pack(side='right')

# 方法三：
tk.Label(window, text=1).place(x=100, y=200, anchor='ne')

# 循环开始程序
window.mainloop()
