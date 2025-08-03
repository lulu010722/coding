#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void print()
    {
        auto it = this;
        while (it)
            cout << it->val << ' ', it = it->next;
        cout << endl;
    }
};

ListNode *makeList(vector<int> array)
{
    ListNode *it = new ListNode;
    auto head = it;
    for (auto i : array)
        it->next = new ListNode(i), it = it->next;
    return head->next;
}

ostream &operator<<(ostream &os, const pair<int, int> &p)
{
    os << "(" << p.first << ", " << p.second << ")";

    return os;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    os << "[";
    for (auto i : vec)
        os << i << ", ";
    os << (vec.empty() ? "]" : "\b\b]");

    return os;
}

template <class T>
ostream &operator<<(ostream &os, const vector<vector<T>> &vecs)
{
    for (auto &vec : vecs)
        cout << vec << endl;

    return os;
}
