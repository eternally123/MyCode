## 简介
>Mutex 又称互斥量，C++ 11中与 Mutex 相关的类（包括锁类型）和函数都声明在 <mutex> 头文件中，所以如果你需要使用 std::mutex，就必须包含 <mutex> 头文件。

>https://www.cnblogs.com/haippy/p/3237213.html

### mutex头文件
#### Mutex 系列类(四种)
- std::mutex，最基本的 Mutex 类。
- std::recursive_mutex，递归 Mutex 类。
- std::time_mutex，定时 Mutex 类。
- std::recursive_timed_mutex，定时递归 Mutex 类。
#### Lock 类（两种）
- std::lock_guard，与 Mutex RAII 相关，方便线程对互斥量上锁。
- std::unique_lock，与 Mutex RAII 相关，方便线程对互斥量上锁，但提供了更好的上锁和解锁控制。
#### 其他类型
- std::once_flag
- std::adopt_lock_t
- std::defer_lock_t
- std::try_to_lock_t
#### 函数
- std::try_lock，尝试同时对多个互斥量上锁。
- std::lock，可以同时对多个互斥量上锁。
- std::call_once，如果多个线程需要同时调用某个函数，call_once 可以保证多个线程对该函数只调用一次。

