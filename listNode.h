struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode *createList(int arr[], int n);
    void printList(ListNode *head);
};

ListNode *createList(int arr[], int n);

void printList(ListNode *head);