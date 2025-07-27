#include "header.h"

struct Compare
{
    bool operator()(const pair<int, ListNode *> &a, const pair<int, ListNode *> &b)
    {
        return a.first > b.first;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, Compare> pq;

        for (int i = 0; i < lists.size(); i++)
            if (lists[i])
                pq.push(make_pair(lists[i]->val, lists[i]));

        ListNode *result = new ListNode;
        auto it = result;
        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            it->next = new ListNode(p.first);
            it = it->next;
            if (p.second->next)
                pq.push(make_pair(p.second->next->val, p.second->next));
        }
        return result->next;
    }
};