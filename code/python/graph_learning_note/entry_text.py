import tkinter as tk


def insert_point():
    var = entry.get()
    text.insert('insert', var)


def insert_end():
    var = entry.get()
    text.insert('end', var)
    # 第一行第一列插入 text.insert(1, 1, var)


window = tk.Tk()  # 一个根窗口
window.title("my window")  # 窗口名
window.geometry('800x800')  # 窗口长宽

# 定义一个文本框输入entry
entry = tk.Entry(window, show=None)
entry.pack()

# 定义两个按钮提供插入功能
button1 = tk.Button(window, text='insert point', width=15, height=2,
                    command=insert_point)
button1.pack()
button2 = tk.Button(window, text='insert end', width=15, height=2,
                    command=insert_end)
button2.pack()

# 定义一个文本框text作为存储
text = tk.Text(window, height=2)
text.pack()

window.mainloop()
