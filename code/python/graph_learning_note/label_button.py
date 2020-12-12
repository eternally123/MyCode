import tkinter as tk

on_hit = False


def hit_me():
    global on_hit
    if on_hit == False:
        on_hit = True
        var.set('you hit me')
    else:
        on_hit = False
        var.set('')


window = tk.Tk()  # 一个根窗口
window.title("my window")  # 窗口名
window.geometry('200x100')  # 窗口长宽

var = tk.StringVar()
label = tk.Label(window, textvariable=var, bg='green',
                 font=('Arial', 16), width=15, height=2)  # 创建一个在window上的label
label.pack()  # 安置label的位置  还有其他方式

button = tk.Button(window, text='hit me', width=15, height=2, command=hit_me)  # 创建一个按钮
button.pack()

window.mainloop()
