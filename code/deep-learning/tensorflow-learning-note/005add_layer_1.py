import tensorflow as tf


# ---------------------learning note---------------------------
#   搭建自己的网络模型：
#   1.确定网络的参数：一般都有输入inputs，输出outputs，输入神经元个数in_size，输出神经元个数out_size
#   2.定义计算过程：
#       deep neuron network 一般都是y=f(w*x+b)，x为输入值，y为输出值，所以要在神经元内部定义w和b
#       w和b都有各自的维度，w维度为[input size,output size]，b维度为[1,output size]
#       f为激活函数，一般有默认值，可以设置为编码人员指定
# -------------------------------------------------------------

def add_layer(inputs, in_size, out_size, activation_function=None):
    Weights = tf.Variable(tf.random_normal(shape=[in_size, out_size]))
    biases = tf.Variable(tf.zeros(shape=[1, out_size]) + 0.1)
    Wx_plus_b = tf.matmul(inputs, Weights) + biases
    if activation_function is None:
        outputs = Wx_plus_b
    else:
        outputs = activation_function(Wx_plus_b)
    return outputs
