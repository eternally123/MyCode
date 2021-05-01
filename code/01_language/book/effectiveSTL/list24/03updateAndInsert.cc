#include <iostream>
#include <map>
#include <typeinfo>
using namespace std;

template <typename MapType, typename KeyType, typename ValueType>
typename MapType::iterator effectiveInsertAndUpdate(MapType &m, const KeyType &k, const ValueType &v)
{
    // 注意判别等价
    auto it = m.lower_bound(k);                         // it < key 为false
    if (it != m.end() && !(m.key_comp()(k, it->first))) // 正确示例  key < it 为false
    {
        it->second = v;
        return it;
    }
    else
    {
        // return m.insert(it, pair<KeyType, ValueType>(k, v));
        return m.insert(it, MVT(k, v));
    }
}

template <typename KeyType, typename ValueType>
map<KeyType, ValueType>::iterator effectiveInsertAndUpdate(map<KeyType, ValueType> &m, const KeyType &k, const ValueType &v)
{
    // 注意判别等价
    auto it = m.lower_bound(k);                         // it < key 为false
    if (it != m.end() && !(m.key_comp()(k, it->first))) // 正确示例  key < it 为false
    {
        it->second = v;
        return it;
    }
    else
    {
        // return m.insert(it, pair<KeyType, ValueType>(k, v));
        return m.insert(it, pair<KeyType, ValueType>(k, v));
    }
}

int main()
{
    map<int, int> m;
    effectiveInsertAndUpdate<map<int, int>, int, int>(m, 1, 1);
    effectiveInsertAndUpdate<map<int, int>, int, int>(m, 1, 2);
    for (auto &it : m)
    {
        cout << it.first << " " << it.second << endl;
    }
    cout << "===========" << endl;
    effectiveInsertAndUpdate<map<int, int>, int, int>(m, 2, 1);
    for (auto &it : m)
    {
        cout << it.first << " " << it.second << endl;
    }
}
/**
 * 这里涉及一些模板编程的内容。还有两点未搞清楚：
 * 1.typename的返回值
 * 2.MVT
 * 
 * 其实这里的函数模板可以不传入MapType
 **/