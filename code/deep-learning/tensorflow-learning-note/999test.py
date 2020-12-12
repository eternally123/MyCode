import tensorflow as tf

a = tf.constant([[[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]], [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]],
                 [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]],dtype=tf.float32)
b = tf.placeholder(dtype=tf.float32, shape=[None, 1])

with tf.Session() as sess:
    print(tf.shape(a))
    print(a.get_shape())
    print(a.shape)
    print(tf.shape(b))
    print(b.get_shape())
    print(b.shape)

    print(tf.reduce_sum(a).shape)
    print(tf.reduce_sum(a, reduction_indices=[0, 1]).shape)
    print(sess.run(tf.reduce_sum(a, reduction_indices=[0, 1])))
    print(tf.reduce_sum(a, reduction_indices=[1]).shape)
    print(sess.run(tf.reduce_sum(a, reduction_indices=[1])))
    print(tf.reduce_sum(a, reduction_indices=[2]).shape)
    print(sess.run(tf.reduce_sum(a, reduction_indices=[2])))

    print(sess.run(tf.reduce_mean(a, reduction_indices=[0, 1])))
    print(sess.run(tf.log(a)))
