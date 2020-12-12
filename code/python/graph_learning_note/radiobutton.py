import tkinter as tk


def print_selection():
    #  config可以改变label所有参数，此处改变的是text
    label.config(text='you have select' + var.get())


window = tk.Tk()
window.title('my title')
window.geometry('800x800')

var = tk.StringVar()
# 定义一个label
label = tk.Label(window, bg='yellow', width=40, text='empty')
label.pack()

# 定义三个radiobutton
radiobutton1 = tk.Radiobutton(window,
                              text='option A', variable=var, value='A',
                              command=print_selection)
radiobutton1.pack()
radiobutton2 = tk.Radiobutton(window,
                              text='option B', variable=var, value='B',
                              command=print_selection)
radiobutton2.pack()
radiobutton3 = tk.Radiobutton(window,
                              text='option C', variable=var, value='C',
                              command=print_selection)
radiobutton3.pack()

tk.mainloop()
