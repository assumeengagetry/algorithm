
#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* createList(const int arr[], int n) {
    ListNode* head = new ListNode();
    ListNode* tail = head;
    for (int i = 0; i < n; ++i) {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }
    return head;
}


void addNodeTail(ListNode* head, int val) {
    ListNode* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = new ListNode(val);
}

void deleteNode(ListNode* head, int val) {
    ListNode *pre = head, *cur = head->next;
    while (cur && cur->val != val) {
        pre = cur;
        cur = cur->next;
    }
    if (cur) {
        pre->next = cur->next;
        delete cur;
    }
}

void printList(ListNode* head) {
    for (ListNode* cur = head->next; cur; cur = cur->next)
        cout << cur->val << " ";
    cout << endl;
}

int main() {
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode* head = createList(arr, n);
    printList(head);
    addNodeTail(head, 99);
    printList(head);
    deleteNode(head, 3);
    printList(head);
    ListNode* cur = head;
    while (cur) {
        ListNode* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    return 0;
}