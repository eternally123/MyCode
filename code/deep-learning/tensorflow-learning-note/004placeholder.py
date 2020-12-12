import tensorflow as tf


# -------------------------------------------------------------
#   tf.placeholder也是用来定义网络中的输入的，但可以不赋初值，并且可以不确定输入参数个数
#   需要给出数据的类型 dtype 维度 shape
# -------------------------------------------------------------

input1 = tf.placeholder(dtype=tf.float32, shape=[None, 2])
# input1 = tf.placeholder(tf.float32,[2,2]) 给定结构为2行2列
# 每一行为一个样本、若一次喂入多组数据则设置为多行，若不知喂入几组则设置为None
input2 = tf.placeholder(dtype=tf.float32, shape=[2, 1])

output = tf.matmul(input1, input2)

with tf.Session() as sess:
    print(sess.run(output, feed_dict={input1: [[7.0, 7.0], [4.0, 4.0]], input2: [[2.0], [2.0]]}))
