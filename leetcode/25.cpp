#include "header.h"

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int n = 0;
        auto it = head;
        vector<ListNode *> nodes;
        while (it && n < k)
        {
            nodes.push_back(it);
            n++;
            it = it->next;
        }
        if (n < k)
            return head;
        for (int i = k - 1; i > 0; i--)
            nodes[i]->next = nodes[i - 1];
        nodes[0]->next = reverseKGroup(it, k);
        return nodes.back();
    }
};