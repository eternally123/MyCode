import tkinter as tk


# 事件print_selection的响应
def print_selection():
    value = listbox.get(listbox.curselection())
    var1.set(value)


# 定义根窗口
window = tk.Tk()  # 一个根窗口
window.title("my window")  # 窗口名
window.geometry('800x800')  # 窗口长宽

# 定义文本输出框
var1 = tk.StringVar()
label = tk.Label(window, bg='yellow', width=4, textvariable=var1)
label.pack()

# 定义按钮提供输出功能，输出至文本输出框
button1 = tk.Button(window, text='print selection', width=15, height=2,
                    command=print_selection)  # 事件print_selection
button1.pack()

# 定义列表供选择
var2 = tk.StringVar()
var2.set((11, 22, 33, 44))
listbox = tk.Listbox(window, listvariable=var2)
listbox.pack()
list_items = [1, 2, 3, 4]
for item in list_items:
    listbox.insert('end', item)
listbox.insert(1, 'first')
listbox.insert(2, 'second')
listbox.delete(2)

# 循环开始程序
window.mainloop()
