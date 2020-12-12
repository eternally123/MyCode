import tkinter as tk

window = tk.Tk()
window.title('my window')
window.geometry('800x800')

label = tk.Label(window, text='on the window')
label.pack()

frame = tk.Frame(window)
frame.pack()
frameleft = tk.Frame(frame)
frameright = tk.Frame(frame)
frameleft.pack(side='left')
frameright.pack(side='right')

labelleft = tk.Label(frameleft, text='on the left')
labelleft.pack()
labelright = tk.Label(frameright, text='on the right')
labelright.pack()

window.mainloop()
