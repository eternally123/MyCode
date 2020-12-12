import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt


def add_layer(inputs, in_size, out_size, activation_function=None):
    Weights = tf.Variable(tf.random_normal(shape=[in_size, out_size]))
    biases = tf.Variable(tf.zeros(shape=[1, out_size]) + 0.1)
    Wx_plus_b = tf.matmul(inputs, Weights) + biases
    if activation_function is None:
        outputs = Wx_plus_b
    else:
        outputs = activation_function(Wx_plus_b)
    return outputs


# ------------------------create data--------------------------
x_data = np.linspace(-1, 1, 300)[:, np.newaxis]
noise = np.random.normal(0, 0.05, x_data.shape)
y_data = np.square(x_data) - 0.5 + noise

# ----------------build tensorflow structure-------------------
xs = tf.placeholder(dtype=tf.float32, shape=[None, 1])  # 输入
ys = tf.placeholder(dtype=tf.float32, shape=[None, 1])  # 输出
l1 = add_layer(xs, 1, 10, activation_function=tf.nn.relu)  # 中间层
prediction = add_layer(l1, 10, 1, activation_function=None)  # 预测值


loss = tf.reduce_mean(tf.reduce_sum(tf.square(ys - prediction),
                                    reduction_indices=[1]))  # loss function

print(tf.shape(tf.reduce_sum(tf.square(ys - prediction))))
print(tf.reduce_sum(tf.square(ys - prediction)).shape)

print(tf.shape(tf.reduce_sum(tf.square(ys - prediction),
                                    reduction_indices=[1])))
print(tf.reduce_sum(tf.square(ys - prediction),
                                    reduction_indices=[1]).shape)
print(tf.shape(tf.square(ys - prediction)))
print(tf.square(ys - prediction).shape)

print(tf.shape(ys-prediction))
print((ys-prediction).shape)

print(tf.shape(ys))
print(ys.shape)





train_step = tf.train.GradientDescentOptimizer(learning_rate=0.1) \
    .minimize(loss=loss)  # 学习速率和优化目标

init = tf.initialize_all_variables()

# ----------------------activate structure----------------------
sess = tf.Session()
sess.run(init)

fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)
ax.scatter(x_data, y_data)
plt.ion()
plt.show()

for i in range(1000):
    sess.run(train_step, feed_dict={xs: x_data, ys: y_data})
    if i % 50 == 0:
        print(sess.run(loss, feed_dict={xs: x_data, ys: y_data}))
        try:
            ax.lines.remove(lines[0])
        except Exception:
            prediction_val = sess.run(prediction, feed_dict={xs: x_data})
            lines = ax.plot(x_data, prediction_val, 'r-', lw=5)
            plt.pause(0.1)
