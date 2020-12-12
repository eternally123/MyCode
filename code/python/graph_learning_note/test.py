import tkinter


def resize(ev=None):
    label.config(font='Helvetica -%d bold' % scale.get())
    pass


top = tkinter.Tk()  # 创建顶层窗口对象，用来存放其他控件
top.geometry('250x150')

label = tkinter.Label(top, text="world")
label.pack()

scale = tkinter.Scale(top, from_=10, to=40, orient=tkinter.HORIZONTAL, command=resize)
scale.set(20)
scale.pack(fill=tkinter.X, expand=1)

quit = tkinter.Button(top, text="hello world", command=top.quit(), bg="red", fg="white")
quit.pack()

text = tkinter.Entry(top, text="hello", command=top.quit())
text.pack(fill=tkinter.X, expand=1)

tkinter.mainloop()
