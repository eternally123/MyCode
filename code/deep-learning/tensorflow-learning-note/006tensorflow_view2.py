import tensorflow as tf
import numpy as np


# ---------------------learning note---------------------------
#   将tensorflow神经网络训练过程的一部分参数画出来：如loss，outputs等等
#       tf.summary.histogram 与 tf.summary.scalar两种summary记录方式 分别记录到history、distribution和scalar
#       tf.summary.merge_all writer.add_summary()
#       1.画每一部分：input、layer、loss、train，用tf.name_scope('input')...来画
#       2.每一部分的内部结构也用tf.name_scope()画，可以递归画出
#   note：声明变量时的name可以自己看一下具体体现在哪里。如tf.placeholder tf.Variable等等
# -------------------------------------------------------------

def add_layer(inputs, in_size, out_size, n_layer, activation_function=None):
    layer_name = 'layer%s' % n_layer
    with tf.name_scope(layer_name):
        with tf.name_scope('weight'):
            Weights = tf.Variable(tf.random_normal(shape=[in_size, out_size]))
            tf.summary.histogram(' ', Weights)  # 加入
        with tf.name_scope('biases'):
            biases = tf.Variable(tf.zeros(shape=[1, out_size]) + 0.1)
            tf.summary.histogram(' ', biases)
        with tf.name_scope('Wx_plus_b'):
            Wx_plus_b = tf.matmul(inputs, Weights) + biases
        if activation_function is None:
            outputs = Wx_plus_b
            tf.summary.histogram('/outputs', outputs)
        else:
            outputs = activation_function(Wx_plus_b)
            tf.summary.histogram('/outputs', outputs)
        return outputs


# ------------------------create data--------------------------
x_data = np.linspace(-1, 1, 300)[:, np.newaxis]
noise = np.random.normal(0, 0.05, x_data.shape)
y_data = np.square(x_data) - 0.5 + noise

# ----------------build tensorflow structure-------------------
with tf.name_scope('input'):
    xs = tf.placeholder(dtype=tf.float32, shape=[None, 1], name='x_input')  # 输入
    ys = tf.placeholder(dtype=tf.float32, shape=[None, 1], name='y_input')  # 输出

l1 = add_layer(xs, 1, 10, n_layer=1, activation_function=tf.nn.relu)  # 中间层
prediction = add_layer(l1, 10, 1, n_layer=2, activation_function=None)  # 预测值

with tf.name_scope('loss'):
    loss = tf.reduce_mean(tf.reduce_sum(tf.square(ys - prediction),
                                        reduction_indices=[1]))  # loss function
    tf.summary.scalar('loss', loss)  # 加入event中
with tf.name_scope('train'):
    train_step = tf.train.GradientDescentOptimizer(learning_rate=0.1) \
        .minimize(loss=loss)  # 学习速率和优化目标

init = tf.initialize_all_variables()

# ----------------------activate structure----------------------
sess = tf.Session()
merged = tf.summary.merge_all()
writer = tf.summary.FileWriter("log/logs2/", sess.graph)

sess.run(init)

for i in range(1000):
    sess.run(train_step, feed_dict={xs: x_data, ys: y_data})
    if i % 50 == 0:
        result = sess.run(merged, feed_dict={xs: x_data, ys: y_data})
        writer.add_summary(result, i)
