#include <iostream>
#include "./listNode.h"

ListNode *createList(int arr[], int n)
{
    if (n == 0)
    {
        return nullptr;
    }
    ListNode *head = new ListNode(arr[0]);
    ListNode *curNode = head;

    for (int i = 1; i < n; i++)
    {
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }
    
    return head;
}

void printList(ListNode *head)
{
    ListNode *curNode = head;
    while (curNode != nullptr)
    {
        std::cout << curNode->val << " ";
        curNode = curNode->next;
    }
    std::cout << std::endl;
}