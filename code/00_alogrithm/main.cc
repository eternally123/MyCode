#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node(int et, int c)
        : endTime_(et)
        , cost_(c)
    {
    }

public:
    int endTime_;
    int cost_;
};

struct comp {
    bool operator()(Node* n1, Node* n2)
    {
        if (n1->endTime_ < n2->endTime_)
            return true;
        if (n1->endTime_ == n2->endTime_ && n1->cost_ < n2->cost_)
            return true;
        return false;
    }
};

int minTime(int n, int t[], int m)
{
    vector<Node*> endTime(n, nullptr);
    priority_queue<Node*, vector<Node*>, comp> pq;

    for (int i = 0; i < n; i++) {
        Node* nd = new Node(t[i], t[i]);
        pq.push(nd);
    }

    while (m > 0) {
        Node* nd = pq.top();
        nd->endTime_ += nd->cost_;
        pq.pop();
        pq.push(nd);
        m--;
    }
    int maxTime = -1;
    while (pq.size() != 0) {
        Node* nd = pq.top();
        pq.pop();
        maxTime = max(maxTime, nd->endTime_ - nd->cost_);
    }
    return maxTime;
}
