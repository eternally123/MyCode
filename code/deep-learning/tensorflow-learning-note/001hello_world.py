import tensorflow as tf
import numpy as np

# -------------------------------------------------------------
#   利用tensorflow搭建模型需要定义以下内容：
#       1.输入输出数据
#       x_data = np.random.rand(100).astype(np.float32)
#       y_data = x_data * 0.1 + 0.3  # 真实值
#
#       2.定义网络结构
#       无隐藏层，只有输入输出层
#
#       3.网络中的参数：常见的有weight和biases
#                       weights = tf.Variable(tf.random_uniform([1], -1.0, 1.0))  # 定义参数变量，一位结构范围-1到1
#                       biases = tf.Variable(tf.zeros([1]))  # 初始值定义为0
#
#       4.定义损失函数、优化函数（方式）、learning rate
#       loss = tf.reduce_mean(tf.square(y - y_data))  # 计算预测值与真实值的差别
#       optimizer = tf.train.GradientDescentOptimizer(0.5)  # 利用此优化器优化误差，指定学习效率
#       train = optimizer.minimize(loss)
#
#       5.初始化、训练
#       for step in range(201):
#           sess.run(train)
#           if step % 20 == 0:
#           print(step, sess.run(weights), sess.run(biases))
# -------------------------------------------------------------

# 本样例预测y=0.1x+0.3曲线
# -----------------------first create data---------------------
x_data = np.random.rand(100).astype(np.float32)
y_data = x_data * 0.1 + 0.3  # 真实值

# -----------------create tensorflow structure ----------------
# 定义网络结构 y = weights * x_data + biases
# 损失函数  loss = tf.reduce_mean(tf.square(y - y_data))
# 学习效率  optimizer = tf.train.GradientDescentOptimizer(0.5)
#          train = optimizer.minimize(loss)
weights = tf.Variable(tf.random_uniform([1], -1.0, 1.0))  # 定义参数变量，一位结构范围-1到1
biases = tf.Variable(tf.zeros([1]))  # 初始值定义为0

y = weights * x_data + biases  # 预测值

loss = tf.reduce_mean(tf.square(y - y_data))  # 计算预测值与真实值的差别
optimizer = tf.train.GradientDescentOptimizer(0.5)  # 利用此优化器优化误差，指定学习效率
train = optimizer.minimize(loss)

init = tf.initialize_all_variables()  # 初始化变量

# ----------------------activate structure----------------------
sess = tf.Session()
sess.run(init)

for step in range(201):
    sess.run(train)
    if step % 20 == 0:
        print(step, sess.run(weights), sess.run(biases))
