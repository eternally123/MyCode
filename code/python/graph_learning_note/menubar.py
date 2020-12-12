import tkinter as tk

counter = 0


def do_job_new():
    global counter
    label.config(text='do' + str(counter))
    counter = counter + 1


window = tk.Tk()
window.title('my window')
window.geometry('800x800')

label = tk.Label(window, text='', bg='yellow')
label.pack()

# tk.Menu创建菜单栏menubar，此处建立在window上
menubar = tk.Menu(window)

filemenu = tk.Menu(menubar, tearoff=0)  # tearoff 是能否被分开
menubar.add_cascade(label='file', menu=filemenu)
editmenu = tk.Menu(menubar, tearoff=0)
menubar.add_cascade(label='edit', menu=editmenu)

filemenu.add_command(label='new', command=do_job_new)
filemenu.add_command(label='open', command=do_job_new)
filemenu.add_command(label='save', command=do_job_new)
filemenu.add_command(label='exit', command=window.quit())
submenu = tk.Menu(menubar, tearoff=0)
filemenu.add_cascade(label='import', menu=submenu)
filemenu.add_separator()  # 是否有下划线

editmenu.add_command(label='new', command=do_job_new)
editmenu.add_command(label='open', command=do_job_new)
editmenu.add_command(label='save', command=do_job_new)

submenu.add_command(label="import one", command=do_job_new)
submenu.add_command(label="import tow", command=do_job_new)

window.config(menu=menubar)
window.mainloop()

# root = tk.Tk()
#
#
# def hello():
#     print('hello')
#
#
# menubar = tk.Menu(root)
#
# # create a pulldown menu, and add it to the menu bar
# filemenu = tk.Menu(menubar, tearoff=0)
#
# filemenu.add_command(label="Open", command=hello)
# filemenu.add_command(label="Save", command=hello)
# filemenu.add_separator()
# filemenu.add_command(label="Exit", command=root.quit)
# menubar.add_cascade(label="File", menu=filemenu)
#
# # create more pulldown menus
# editmenu = tk.Menu(menubar, tearoff=0)
# editmenu.add_command(label="Cut", command=hello)
# editmenu.add_command(label="Copy", command=hello)
# editmenu.add_command(label="Paste", command=hello)
# menubar.add_cascade(label="Edit", menu=editmenu)
#
# helpmenu = tk.Menu(menubar, tearoff=0)
# helpmenu.add_command(label="About", command=hello)
# menubar.add_cascade(label="Help", menu=helpmenu)
#
# # display the menu
# root.config(menu=menubar)
#
# root.mainloop()
