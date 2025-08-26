#include "header.h"

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        int n = 0;
        auto it = head;
        auto tail = it;
        while (it)
            n++, tail = it, it = it->next;
        if (n <= 1)
            return head;
        k %= n;
        if (k == 0)
            return head;
        auto newHead = head;
        for (int i = 0; i < n - k; i++)
            newHead = newHead->next;
        for (int i = 0; i < n - k; i++)
            tail->next = head, head = head->next, tail = tail->next;
        tail->next = nullptr;
        return newHead;
    }
};