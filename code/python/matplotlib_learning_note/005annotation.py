import matplotlib.pyplot as plt
import numpy as np

# ----------------------------------------------
#            添加注解(繁琐最好不要用)
# ----------------------------------------------

x = np.linspace(-3, 3, 50)
y1 = 2 * x + 1
y2 = x ** 2

plt.figure()
plt.plot(x, y1)  # plt.scatter绘制散点图

# something new
ax = plt.gca()  # 拿出上下左右轴
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')

ax.spines['bottom'].set_position(('data', 0))  # outward,axes
ax.spines['left'].set_position(('data', 0))

x0 = 1
y0 = 2 * x0 + 1
plt.scatter(x0, y0, color='r')
plt.plot([x0, x0], [y0, 0], 'k--', lw=2.5)

# 使用注解
# method 1
plt.annotate(r'$2x+1=3$', xy=(x0, y0), xycoords='data', xytext=(+30, -30), textcoords='offset points', fontsize=16,
             arrowprops=dict(arrowstyle='->', connectionstyle='arc3,rad=0.2'))
# method 2
plt.text(-3.7, 3, r'$this\ is\ the\ some\ text.\mu\ \sigma_i\ \alpha_t$', fontdict={'size': 16, 'color': 'r'})

plt.show()
