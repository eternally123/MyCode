#include <iostream>
#include <algorithm>
#include <cctype>

template <class Os, class Co>
Os &operator<<(Os &os, const Co &v)
{
    for (auto i : v)
        os << i << ' ';
    return os;
}

int main()
{
    const auto
        v1 = {'a', 'b', 'c', 'f', 'h', 'x'},
        v2 = {'a', 'b', 'c'},
        v3 = {'a', 'c'},
        v4 = {'a', 'a', 'b'},
        v5 = {'g'},
        v6 = {'a', 'c', 'g'},
        v7 = {'A', 'B', 'C'};

    auto no_case = [](char a, char b) { return std::tolower(a) < std::tolower(b); };

    std::cout
        << v1 << "\nincludes:\n"
        << std::boolalpha
        << v2 << ": " << std::includes(v1.begin(), v1.end(), v2.begin(), v2.end()) << '\n'
        << v3 << ": " << std::includes(v1.begin(), v1.end(), v3.begin(), v3.end()) << '\n'
        << v4 << ": " << std::includes(v1.begin(), v1.end(), v4.begin(), v4.end()) << '\n'
        << v5 << ": " << std::includes(v1.begin(), v1.end(), v5.begin(), v5.end()) << '\n'
        << v6 << ": " << std::includes(v1.begin(), v1.end(), v6.begin(), v6.end()) << '\n'
        << v7 << ": " << std::includes(v1.begin(), v1.end(), v7.begin(), v7.end(), no_case)
        << " (case-insensitive)\n";
}

/**
 * 若已排序范围 [first2, last2) 是已排序范围 [first1, last1) 的子序列
 * 则返回 true 。（子序列不必相接。）
 **/