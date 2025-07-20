#include "2.cpp"

int main()
{
    Solution Solution;
    ListNode *l1 = new ListNode(9);
    auto h1 = l1;
    h1->next = new ListNode(9);
    h1 = h1->next;
    h1->next = new ListNode(9);
    h1 = h1->next;
    h1->next = new ListNode(9);
    h1 = h1->next;
    h1->next = new ListNode(9);
    h1 = h1->next;
    h1->next = new ListNode(9);
    h1 = h1->next;
    h1->next = new ListNode(9);
    h1 = h1->next;

    ListNode *l2 = new ListNode(9);
    auto h2 = l2;
    h2->next = new ListNode(9);
    h2 = h2->next;
    h2->next = new ListNode(9);
    h2 = h2->next;
    h2->next = new ListNode(9);
    h2 = h2->next;

    auto solution = Solution.addTwoNumbers(l1, l2);
    while (solution)
    {
        cout << solution->val << endl;
        solution = solution->next;
    }
    return 0;
}