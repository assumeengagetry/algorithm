#include<iostream>
using namespace std;


struct Node
{
    int xishu;
    int zhishu;
    Node *next;
    Node(int xishu = 0, int zhishu = 0,Node *next = nullptr) : xishu(xishu) , zhishu(zhishu), next(next) {}

    /* data */
};

Node *CreateNode(const int xishu[], const int zhishu[], int n){
 Node *head = new Node();
 Node *tail = head;
 for (int i = 0; i <= n ; i++){
    tail -> next = new Node(xishu[i], zhishu[i]);
    tail =  tail -> next;
 
 }
 return head;   
}
void printNode(Node* head) {
    Node* cur = head->next;
    bool first = true;
    while (cur) {
        if (!first && cur->xishu > 0) cout << "+";
        cout << cur->xishu;
        if (cur->zhishu > 0) cout << "x^" << cur->zhishu;
        first = false;
        cur = cur->next;
    }
    cout << endl;
}


Node* addNode(Node *p1, Node *p2){
    Node *head = new Node();
    Node *tail = head;
    Node *a= p1 -> next , *b = p2 -> next;
    while(a && b){
        if(a -> zhishu > b -> zhishu){
            tail -> next = new Node(a -> zhishu, a-> xishu);
            a = a -> next;
        }
        else if( a -> zhishu < b -> zhishu){
            tail -> next = new Node(b -> zhishu, b -> xishu);
        }
        else {
            int sum = a -> zhishu + b -> zhishu;
            if (sum != 0) {
                tail -> next = new Node(sum , a-> xishu);
            }
            a = a-> next;
            b = b -> next;
        }
        if (tail -> next != nullptr) tail = tail -> next;
    }
        while (a) {
        tail->next = new Node(a->zhishu, a->xishu);
        tail = tail->next;
        a = a->next;
    }
    while (b) {
        tail->next = new Node(b->zhishu, b->xishu);
        tail = tail->next;
        b = b->next;
    }
    return head;
}



int main() {
    // 多项式1: 3x^4 + 2x^2 + 1
    int coef1[] = {3, 2, 1};
    int exp1[]  = {4, 2, 0};
    Node* poly1 = CreateNode(coef1, exp1, 3);
    cout << "P1(x) = ";
    printNode(poly1);
    // 多项式2: 5x^3 + 2x^2 + 4
    int coef2[] = {5, 2, 4};
    int exp2[]  = {3, 2, 0};
    Node* poly2 = CreateNode(coef2, exp2, 3);
    cout << "P2(x) = ";
    printNode(poly2);

    // 多项式加法
    Node* sum = addNode(poly1, poly2);
    cout << "P1(x) + P2(x) = ";
    printNode(sum);
    
    // 释放内存
    for (Node* cur : {poly1, poly2, sum}) {
        Node* p = cur;
        while (p) {
            Node* tmp = p;
            p = p->next;
            delete tmp;
        }
    }
    return 0;
}
