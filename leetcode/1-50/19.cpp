#include "header.h"

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *it = head;
        int size = 0;
        while (it)
            size++, it = it->next;

        if (size == n)
            return head->next;

        auto curr = head;
        auto prev = head;
        for (int i = 0; i < size - n; i++)
            prev = curr, curr = curr->next;

        prev->next = curr->next;
        delete curr;
        return head;
    }
};