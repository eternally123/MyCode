## 排序算法
### 针对随机访问迭代器
- sort、stable_sort、partial_sort、nth_element都可以。（不能用于链表等不可随机访问的）
### 针对list
- 提供了sort成员函数进行排序
- 可以复制到随机访问迭代器中排序
- 可以创建list::iterator，然后对其排序，通过list::iterator访问list即可得到有序的
- 利用splice成员函数，反复调用