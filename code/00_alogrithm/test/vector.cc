#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        int size = arr.size();
        int sortingSize = size;
        int num = k;
        while (num > 0)
        {
            int index = sortingSize / 2 - 1;
            while (index >= 0)
            {
                if (arr[index] <= arr[2 * index + 1] && arr[index] <= arr[2 * index + 2])
                {
                    index--;
                    continue;
                }

                int tmp;
                if (arr[2 * index + 1] < arr[2 * index + 2])
                {
                    tmp = arr[index];
                    arr[index] = arr[2 * index + 1];
                    arr[2 * index + 1] = tmp;
                    index--;
                    continue;
                }
                else
                {
                    tmp = arr[index];
                    arr[index] = arr[2 * index + 2];
                    arr[2 * index + 2] = tmp;
                    index--;
                    continue;
                }
            }
            int tmp = arr[0];
            arr[0] = arr[sortingSize - 1];
            arr[sortingSize - 1] = tmp;

            sortingSize--;
            num--;
        }
        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(arr[size - 1 - i]);
            sort(result.begin(), result.end());
        }
        return result;
    }
};

int main()
{
    vector<int> v = {3, 2, 1};
    int size = 2;
    Solution s;
    auto result = s.getLeastNumbers(v, size);
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;
}