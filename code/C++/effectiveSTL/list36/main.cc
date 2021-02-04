#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

int main()
{
    std::vector<int> from_vector(10);
    std::iota(from_vector.begin(), from_vector.end(), 0);

    std::vector<int> to_vector;
    std::copy(from_vector.begin(), from_vector.end(),
              std::back_inserter(to_vector));
    // 或可选地，
    //  std::vector<int> to_vector(from_vector.size());
    //  std::copy(from_vector.begin(), from_vector.end(), to_vector.begin());
    // 任一方式都等价于
    //  std::vector<int> to_vector = from_vector;

    std::cout << "to_vector contains: ";

    std::copy(to_vector.begin(), to_vector.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    std::cout << "odd numbers in to_vector are: ";

    std::copy_if(to_vector.begin(), to_vector.end(),
                 std::ostream_iterator<int>(std::cout, " "),
                 [](int x) { return (x % 2) == 1; });
    std::cout << '\n';
}

/**
 * 复制 [first, last) 所定义的范围中的元素到始于 d_first 的另一范围。
 **/