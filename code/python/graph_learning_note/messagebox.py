import tkinter as tk
from tkinter import messagebox


def hit_me():
    # tk.messagebox.showinfo(title='hi', message='hahahahah')
    # tk.messagebox.showwarning(title='hi', message='nonononono')
    # tk.messagebox.showerror(title='hi', message='wrong wrong wrong...')
    # print(tk.messagebox.askquestion(title='hi', message='please choose'))  # return yes or no
    # print(tk.messagebox.askyesno(title='hi', message='please choose'))  # return true or false
    # print(tk.messagebox.askretrycancel(title='hi', message='please choose'))  # return yes or no
    print(tk.messagebox.askyesnocancel(title='hi', message='please choose'))  # return yes or no
    # ......something more


window = tk.Tk()
window.title('my window')
window.geometry('800x800')

tk.Button(window, text='hit me', command=hit_me).pack()

window.mainloop()
