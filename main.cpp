#include <iostream>
#include "./listNode.h"

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        ListNode *first = head;
        ListNode *prevSlow = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prevSlow->next = nullptr;

        ListNode *second = reverseList(slow);

        ListNode *prevSecond = nullptr;

        while (first != nullptr && second != nullptr)
        {
            prevSecond = second;
            ListNode *firstNext = first->next;
            ListNode *secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }

        if (prevSecond != slow)
        {
            prevSecond->next = slow;
        }

        head = first;

        return;
    }

private:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next = nullptr;

        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};

main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode *head = createList(arr, n);

    std::cout << "Original list: " << std::endl;
    printList(head);

    Solution solution = Solution();
    solution.reorderList(head);

    std::cout << "\nReversed list: " << std::endl;
    printList(head);

    return 0;
}