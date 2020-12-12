import tkinter as tk


def print_selection():
    if (var1.get() == 1) & (var2.get() == 0):
        label.config(text='I love only python')
    if (var1.get() == 0) & (var2.get() == 1):
        label.config(text='I love only c++')
    if (var1.get() == 0) & (var2.get() == 0):
        label.config(text='I love neither')
    if (var1.get() == 1) & (var2.get() == 1):
        label.config(text='I love both')


window = tk.Tk()
window.title('my window')
window.geometry('400x400')

label = tk.Label(window, bg='yellow', width=20, text='empty')
label.pack()

var1 = tk.IntVar()
var2 = tk.IntVar()
checkbutton1 = tk.Checkbutton(window, text='python', variable=var1,
                              onvalue=1, offvalue=0, command=print_selection)
checkbutton1.pack()
checkbutton2 = tk.Checkbutton(window, text='c++', variable=var2,
                              onvalue=1, offvalue=0, command=print_selection)
checkbutton2.pack()


tk.mainloop()
