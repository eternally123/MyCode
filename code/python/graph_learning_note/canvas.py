import tkinter as tk


def move_it():
    canvas.move(oval, 0, -20)


window = tk.Tk()
window.title('my window')
window.geometry('1600x1600')

# 画布
canvas = tk.Canvas(window, bg='blue', height=800, width=800)
image_file = tk.PhotoImage(file="/home/shiliangw/Pictures/picture.gif")
image = canvas.create_image(0, 0, anchor='nw', image=image_file)
x0, y0, x1, y1 = 500, 500, 800, 800
line = canvas.create_line(x0, y0, x1, y1, fill='red')
oval = canvas.create_oval(x0, y0, x1, y1, fill='yellow')
canvas.pack()

# 移动按钮
button = tk.Button(window, text='move', command=move_it)
button.pack()

tk.mainloop()
