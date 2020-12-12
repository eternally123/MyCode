import matplotlib.pyplot as plt
import numpy as np

# ----------------------------------------------
#                     做图例
# ----------------------------------------------

x = np.linspace(-3, 3, 50)
y1 = 2 * x + 1
y2 = x ** 2

plt.figure()

plt.xlim((-1, 2))
plt.ylim((-2, 3))
plt.xlabel('i am x')
plt.ylabel('i am y')

# new_ticks = np.linspace(-1, 2, 5)
# plt.xticks(new_ticks)
# # plt.yticks([-2, -1.8, -1, 1.22, 3], ['really bad', 'bad', 'normal', 'good', 'very good'])  # 字体也可以改变，特殊符号一般都和LaTeX一样
# plt.yticks([-2, -1.8, -1, 1.22, 3],
#            [r'$really\ bad', r'$bad$', r'$normal$', r'$good\alpha$', r'very\ good'])  # 字体也可以改变，特殊符号一般都和LaTeX一样

# something new
# ax = plt.gca()  # 拿出上下左右轴
# ax.spines['right'].set_color('none')
# ax.spines['top'].set_color('none')
# ax.xaxis.set_ticks_position('bottom')
# ax.yaxis.set_ticks_position('left')
#
# ax.spines['bottom'].set_position(('data', 0))  # outward,axes
# ax.spines['left'].set_position(('data', 0))

l1, = plt.plot(x, y1, label='up')
l2,= plt.plot(x, y2, color='red', linewidth=3.0, linestyle='--', label='down')
plt.legend(handles=[l1, l2], labels=['aaa'], loc='best')

plt.show()
