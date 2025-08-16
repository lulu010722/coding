#include "header.h"

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
            return nullptr;
        if (!head->next)
            return head;
        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *third = head->next->next;
        second->next = first;
        first->next = swapPairs(third);
        return second;
    }
};