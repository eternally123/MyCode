#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <mutex>
#include <fstream>

std::string delimiter = ":";

// 跳跃表节点
template <typename K, typename V>
class Node
{

public:
    Node() {}
    Node(K k, V v, int);
    ~Node();

public:
    K get_key() const;
    V get_value() const;
    void set_value(V);
    Node<K, V> **forward; // 记录不同level的节点
    int node_level;

private:
    K key;
    V value;
};

// 含空节点的跳跃表
template <typename K, typename V>
class SkipList
{

public:
    SkipList(int);
    ~SkipList();
    int insert(K, V);
    bool search(K);
    void erase(K);
    int size();

private:
    int get_random_level();
    void display_list();
    Node<K, V> *create_node(K, V, int);

private:
    int _max_level;       // 跳表最大level
    int _skip_list_level; // 跳表当前的最大level
    Node<K, V> *_header;  // 跳表的首节点
    int _element_count;   // 跳表中节点个数
};

template <typename K, typename V>
Node<K, V>::Node(const K k, const V v, int level)
{
    this->key = k;
    this->value = v;
    this->node_level = level;

    // level + 1, because array index is from 0 - level
    this->forward = new Node<K, V> *[level + 1];

    // Fill forward array with 0(NULL)
    memset(this->forward, 0, sizeof(Node<K, V> *) * (level + 1));
};

template <typename K, typename V>
Node<K, V>::~Node()
{
    delete[] forward;
};

template <typename K, typename V>
K Node<K, V>::get_key() const
{
    return key;
};

template <typename K, typename V>
V Node<K, V>::get_value() const
{
    return value;
};

template <typename K, typename V>
void Node<K, V>::set_value(V value)
{
    this->value = value;
};

// create new node
template <typename K, typename V>
Node<K, V> *SkipList<K, V>::create_node(const K k, const V v, int level)
{
    Node<K, V> *n = new Node<K, V>(k, v, level);
    return n;
}

// Insert given key and value in skip list
// return 1 means element exists
// return 0 means insert successfully
/* 
                           +------------+
                           |  insert 50 |
                           +------------+
level 4     +-->1+                                                      100
                 |
                 |                      insert +----+
level 3         1+-------->10+---------------> | 50 |          70       100
                                               |    |
                                               |    |
level 2         1          10         30       | 50 |          70       100
                                               |    |
                                               |    |
level 1         1    4     10         30       | 50 |          70       100
                                               |    |
                                               |    |
level 0         1    4   9 10         30   40  | 50 |  60      70       100
                                               +----+
*/
// insert kv
template <typename K, typename V>
int SkipList<K, V>::insert(const K key, const V value)
{
    Node<K, V> *current = this->_header;

    // create update array and initialize it
    // update is array which put node that the node->forward[i] should be operated later
    Node<K, V> *update[_max_level + 1];
    memset(update, 0, sizeof(Node<K, V> *) * (_max_level + 1));

    // start form highest level of skip list
    for (int i = _skip_list_level; i >= 0; i--)
    {
        while (current->forward[i] != NULL && current->forward[i]->get_key() < key)
        {
            current = current->forward[i];
        }
        update[i] = current;
    }

    // reached level 0 and forward pointer to right node, which is desired to insert key.
    current = current->forward[0];

    // if current node have key equal to searched key, we get it
    if (current != NULL && current->get_key() == key)
    {
        return 1;
    }

    // if current is NULL that means we have reached to end of the level
    // if current's key is not equal to key that means we have to insert node between update[0] and current node
    if (current == NULL || current->get_key() != key)
    {

        // Generate a random level for node
        int random_level = get_random_level();

        // If random level is greater thar skip list's current level, initialize update value with pointer to header
        if (random_level > _skip_list_level)
        {
            for (int i = _skip_list_level + 1; i < random_level + 1; i++)
            {
                update[i] = _header;
            }
            _skip_list_level = random_level;
        }

        // create new node with random level generated
        Node<K, V> *inserted_node = create_node(key, value, random_level);

        // insert node
        for (int i = 0; i <= random_level; i++)
        {
            inserted_node->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = inserted_node;
        }
        _element_count++;
    }
    return 0;
}

// Display skip list
template <typename K, typename V>
void SkipList<K, V>::display_list()
{
    for (int i = 0; i <= _skip_list_level; i++)
    {
        Node<K, V> *node = this->_header->forward[i];
        while (node != NULL)
        {
            node = node->forward[i];
        }
        std::cout << std::endl;
    }
}

// Get current SkipList size
template <typename K, typename V>
int SkipList<K, V>::size()
{
    return _element_count;
}

// Delete element from skip list
template <typename K, typename V>
void SkipList<K, V>::erase(K key)
{

    Node<K, V> *current = this->_header;
    Node<K, V> *update[_max_level + 1];
    memset(update, 0, sizeof(Node<K, V> *) * (_max_level + 1));

    // 从最大的level开始查找
    for (int i = _skip_list_level; i >= 0; i--)
    {
        while (current->forward[i] != NULL && current->forward[i]->get_key() < key)
        {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];
    if (current != NULL && current->get_key() == key)
    {
        // current就是要删除的节点
        // 要更改所有层的指针，update数组存放的是prev指针
        for (int i = 0; i <= _skip_list_level; i++)
        {

            // if at level i, next node is not target node, break the loop.
            if (update[i]->forward[i] != current)
                break;

            update[i]->forward[i] = current->forward[i];
        }

        // 从最高一层开始，判断空层，更改当前最大层数
        while (_skip_list_level > 0 && _header->forward[_skip_list_level] == 0)
        {
            _skip_list_level--;
        }

        _element_count--;
    }
    return;
}

// Search for element in skip list
/*
                           +------------+
                           |  select 60 |
                           +------------+
level 4     +-->1+                                                      100
                 |
                 |
level 3         1+-------->10+------------------>50+           70       100
                                                   |
                                                   |
level 2         1          10         30         50|           70       100
                                                   |
                                                   |
level 1         1    4     10         30         50|           70       100
                                                   |
                                                   |
level 0         1    4   9 10         30   40    50+-->60      70       100
*/
template <typename K, typename V>
bool SkipList<K, V>::search(K key)
{
    Node<K, V> *current = _header;

    // 从最大的level开始查找
    for (int i = _skip_list_level; i >= 0; i--)
    {
        while (current->forward[i] && current->forward[i]->get_key() < key)
        {
            current = current->forward[i];
        }
    }

    // current的下一个就是我们要找的元素，但是可能不存在，需要判断
    current = current->forward[0];

    // 如果下一个元素不是空，且key与指定的相等，则找到
    if (current and current->get_key() == key)
    {
        return true;
    }

    return false;
}

template <typename K, typename V>
SkipList<K, V>::SkipList(int max_level)
{

    this->_max_level = max_level;
    this->_skip_list_level = 0;
    this->_element_count = 0;

    // 构造节点并初始化首节点
    K k;
    V v;
    this->_header = new Node<K, V>(k, v, _max_level);
};

template <typename K, typename V>
SkipList<K, V>::~SkipList()
{
    delete _header;
}

template <typename K, typename V>
int SkipList<K, V>::get_random_level()
{

    int k = 1;
    while (rand() % 2)
    {
        k++;
    }
    k = (k < _max_level) ? k : _max_level;
    return k;
};
