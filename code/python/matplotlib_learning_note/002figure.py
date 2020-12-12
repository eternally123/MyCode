import matplotlib.pyplot as plt
import numpy as np

# ----------------------------------------------
#    绘制多张图片，定义图片序号，定义线的种类和颜色
# ----------------------------------------------

x = np.linspace(-1, 1, 50)
y1 = 2 * x + 1
y2 = x ** 2

# 默认figure会从1依次排，但可以指定
# plt.figure()
# plt.plot(x, y1)
# plt.figure()
# plt.plot(x, y2)
# plt.show()

# 指定参数
# plt.figure()
# plt.plot(x, y1)
# plt.figure(num=3, figsize=(8, 5))
# plt.plot(x, y2)
# plt.show()

# 一张图画多条线
plt.figure()
plt.plot(x, y1)
plt.plot(x, y2, color='red', linewidth=3.0, linestyle='--')
plt.show()
