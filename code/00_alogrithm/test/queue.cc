#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    queue<int> p;
    q.push(1);
    p.push(2);
    swap(q, p);
    cout << q.front();
}