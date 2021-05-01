#include <queue>
#include <iostream>

using namespace std;

int main()
{
    priority_queue<int> q;
    q.push(1);
    q.push(5);
    q.push(2);
    q.push(6);
    q.push(9);
    q.push(3);
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}