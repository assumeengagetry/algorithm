#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
private:
    int _size;
    ListNode* dummyhead;

public:
    MyLinkedList() {
        dummyhead = new ListNode(0);
        _size = 0;
    }

    ~MyLinkedList() {
        ListNode* current = dummyhead;
        while (current != NULL) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
    }

    int get(int index) {
        if (index > _size - 1 || index < 0) {
            return -1;
        }
        ListNode* cur = dummyhead->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        ListNode* newnode = new ListNode(val);
        newnode->next = dummyhead->next;
        dummyhead->next = newnode;
        _size++;
    }

    void addAtTail(int val) {
        ListNode* newnode = new ListNode(val);
        ListNode* current = dummyhead;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (index > _size) return;
        if (index < 0) index = 0;
        ListNode* newnode = new ListNode(val);
        ListNode* current = dummyhead;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
        _size++;
    }

    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) return;
        ListNode* current = dummyhead;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        ListNode* temp = current->next;
        current->next = temp->next;
        delete temp;
        _size--;
    }

    void printList() {
        ListNode* current = dummyhead->next;
        while (current != NULL) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main()
{
    
}