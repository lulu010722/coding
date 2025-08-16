#include "header.h"

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        auto it1 = list1;
        auto it2 = list2;
        ListNode *result = new ListNode();
        auto it = result;
        while (it1 && it2)
        {
            if (it1->val < it2->val)
                it->next = new ListNode(it1->val), it1 = it1->next;
            else
                it->next = new ListNode(it2->val), it2 = it2->next;
            it = it->next;
        }
        while (it1)
        {
            it->next = new ListNode(it1->val);
            it = it->next;
            it1 = it1->next;
        }
        while (it2)
        {
            it->next = new ListNode(it2->val);
            it = it->next;
            it2 = it2->next;
        }

        return result->next;
    }
};