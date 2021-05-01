## 容器的删除操作
### 删除某个值
- 对于顺序容器，可以利用erase成员函数+remove函数（erase_value/01sequentialContainer.cc）
- 对于list，利用remove成员函数更高效（erase_value/02list.cc）
- 对于关联容器，利用erase成员函数（erase_value/03assocContainer.cc）

### 删除符合某个条件的值
- 对于顺序容器，可以利用erase成员函数+remove_if函数(erase_by_discriminant/03sequenceContainer.cc)
- 对于list，利用remove_if成员函数更高效（erase_by_discriminant/04list.cc）
- 对于关联容器，利用remove_copy_if函数和swap成员函数（对于list，利用remove_if成员函数更高效（erase_by_discriminant/01-02.cc）

### 对于删除时需要做日志的情况
都可以采用遍历的方式。然后用erase成员函数删除迭代器对应的元素。（erase_with_log）

对于关联容器，删除某个元素不会改变其他的元素迭代器，但是对于顺序容器，删除某个元素会让被删除元素之后的迭代器都无效。

- 对于顺序容器，删除时需要记录erase成员函数返回值作为下次判断用到的迭代器。
- 对于关联容器，需要在删除前+1，即erase成员函数内用i++的方式