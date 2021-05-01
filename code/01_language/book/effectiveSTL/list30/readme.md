## 确保区间足够大
- 利用push_front、push_back、insert等操作加入新元素时，STL会自动扩容
- 当利用transform添加新元素时，使用不当可能会导致运行时错误

### transform
- transform对指定迭代器区间内的每个元素调用一个函数，然后将结果写到指定位置。
- 如果指定位置是：①迭代器位置，则可能会出现覆盖原位置数据的问题，如果是无效位置如end还可能会出现非法访问。②inserter系列函数指定位置，包括front_inserter、back_inserter、inserter之类的，原理相当于调用了push_back、push_front这种逐个进行插入，效率可能低下。
- 如果想效率高，则需要reserve扩容，然后在执行这中操作，避免了插入期间扩容造成更大量数据的拷贝。
