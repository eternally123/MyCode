import tensorflow as tf

# -------------------------------------------------------------
#   tf.Variable是用来定义网络中的变量的
#   需要给出数据的类型 初始值
#   对于变量的操作需通过tf.add tf.assign tf.mutual等实现
# -------------------------------------------------------------

state = tf.Variable(initial_value=0, name='counter')
# print(state.name)
one = tf.constant(1)
new_value = tf.add(state, one)
update = tf.assign(state, new_value)

init = tf.initialize_all_variables()

with tf.Session() as sess:
    sess.run(init)  # 激活所有参数
    for _ in range(3):
        sess.run(update)
        print(sess.run(state))
