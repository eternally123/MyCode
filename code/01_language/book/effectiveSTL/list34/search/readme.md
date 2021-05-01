## 查找算法
STL中对于有序序列（vector,list等）提供了相当相当强大的二分搜索Binary search算法。对于可以随机访问容器（如vector等），binary search负载度为对数级别（LogN)，对于非随机访问容器（如list），则算法复杂度为线性。现在简要介绍一下几种常用的binary search算法：

### lower_bound
Iterator lower_bound (Iterator first,Iterator last, const T& value)
Iterator lower_bound (Iterator first,Iterator last, const T& value, Compare comp)
- 返回一个迭代器，指向键值>=value的第一个元素

### upper_bound
Iterator upper_bound (Iterator first,Iterator last, const T& value)
Iterator upper_bound (Iterator first,Iterator last, const T& value, Compare comp)
- 返回一个迭代器，指向键值>value的第一个元素（注意此处与上一个的区别）.

### equal_range
pair equal_range(Iterator first, Iterator last, const T& value)
pair equal_range(Iterator first, Iterator last, const T& value, Compare comp)
- 试图在已排序的[first,last)中寻找value，它返回一对迭代器i和j，其中i是在不破坏次序的前提下，value可插入的第一个位置（亦即lower_bound），j则是在不破坏次序的前提下，value可插入的最后一个位置（亦即upper_bound），因此，[i,j)内的每个元素都等同于value，而且[i,j)是[first,last)之中符合此一性质的最大子区间

### binary_search
bool binary_search (ForwardIterator first, ForwardIterator last, const T& value)
bool binary_search (ForwardIterator first, ForwardIterator last, const T& value, Compare comp)
- 查找是否在[first,last)中存在iterator i,满足 !(*i<value) && !(value<*i) or comp(*i,value)==false && comp(value,*i)==false
- 存在则返回true,否则返回false. 