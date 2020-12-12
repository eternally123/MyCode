import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data

# ---------------------learning note---------------------------
#   利用tensorflow做分类问题：
#       1.常将softmax函数作为activation_function。在做回归时通常不用activation_function或者其他的
#       2.loss通常用cross_entropy:
#           cross_entropy = tf.reduce_mean(-tf.reduce_sum(ys * tf.log(prediction),
#                                                   reduction_indices=[1]))  # loss
#         回归时，loss通常选用均方差
#           loss = tf.reduce_mean(tf.reduce_sum(tf.square(ys - prediction),
#                                         reduction_indices=[1]))  # loss function
# -------------------------------------------------------------

# number 1 to 10 data
mnist = input_data.read_data_sets('data/MNIST_data', one_hot=True)  # data文件夹中


def add_layer(inputs, in_size, out_size, activation_function=None, ):
    # add one more layer and return the output of this layer
    Weights = tf.Variable(tf.random_normal([in_size, out_size]))
    biases = tf.Variable(tf.zeros([1, out_size]) + 0.1, )
    Wx_plus_b = tf.matmul(inputs, Weights) + biases
    if activation_function is None:
        outputs = Wx_plus_b
    else:
        outputs = activation_function(Wx_plus_b, )
    return outputs


def compute_accuracy(v_xs, v_ys):
    global prediction
    y_pre = sess.run(prediction, feed_dict={xs: v_xs})  # 利用x通过神经网络生成预测值y_pre，但不一定时0或1，有小数
    correct_prediction = tf.equal(tf.argmax(y_pre, 1), tf.argmax(v_ys, 1))
    accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
    result = sess.run(accuracy, feed_dict={xs: v_xs, ys: v_ys})
    return result  # result是一个百分比，代表正确率


# define placeholder for inputs to network
xs = tf.placeholder(tf.float32, [None, 784])  # 28x28每张图片有784个像素点
ys = tf.placeholder(tf.float32, [None, 10])  # 10个输出代表0-9

# add output layer
prediction = add_layer(xs, 784, 10, activation_function=tf.nn.softmax)

# the error between prediction and real data
cross_entropy = tf.reduce_mean(-tf.reduce_sum(ys * tf.log(prediction), reduction_indices=[1]))  # loss
# cross_entropy2 = tf.reduce_sum(-tf.reduce_mean(ys * tf.log(prediction), reduction_indices=[0]))
# 验证corss_entropy2=cross_entropy,因计算方式不同，四舍五入会有差异，故选用两种方法算出来有点差别

train_step = tf.train.GradientDescentOptimizer(learning_rate=0.5).minimize(loss=cross_entropy)

print(tf.reduce_sum(ys * tf.log(prediction)).shape)

sess = tf.Session()
# important step
# tf.initialize_all_variables() no long valid from

if int((tf.__version__).split('.')[1]) < 12 \
        and int((tf.__version__).split('.')[0]) < 1:
    init = tf.initialize_all_variables()
else:
    init = tf.global_variables_initializer()
sess.run(init)

for i in range(1000):
    batch_xs, batch_ys = mnist.train.next_batch(100)
    sess.run(train_step, feed_dict={xs: batch_xs, ys: batch_ys})
    # print(sess.run(prediction, feed_dict={xs: batch_xs, ys: batch_ys}))
    if i % 50 == 0:
        # print(sess.run(cross_entropy, feed_dict={xs: batch_xs, ys: batch_ys}))
        # print(sess.run(cross_entropy2, feed_dict={xs: batch_xs, ys: batch_ys}))
        print(compute_accuracy(mnist.test.images, mnist.test.labels))
