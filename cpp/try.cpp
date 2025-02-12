#include <iostream>
using namespace std;
// 定义链表节点结构体
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {} // 初始化列表节点
};

// 定义链表类
class LinkedList {
private:
    ListNode* head; // 虚拟头节点

public:
    // 构造函数
    LinkedList() {
        head = new ListNode(0); // 创建一个虚拟头节点，值为0
    }

    // 析构函数
    ~LinkedList() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
    }

    // 向链表中插入一个新节点
    void insert(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head->next;
        head->next = newNode;
    }

    // 删除链表中的一个节点
    void remove(int val) {
        ListNode* current = head;
        while (current->next != nullptr) {
            if (current->next->val == val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    // 打印链表
    void printList() {
        ListNode* current = head->next;
        while (current != nullptr) {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    std::cout << "Initial list: ";
    list.printList();

    list.remove(2);
    std::cout << "List after removing 2: ";
    list.printList();

    return 0;
}