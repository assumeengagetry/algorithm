#include <iostream>
using namespace std;

// 多项式项结点
struct PolyNode {
    int coef; // 系数
    int exp;  // 指数
    PolyNode *next;
    PolyNode(int c = 0, int e = 0, PolyNode *n = nullptr) : coef(c), exp(e), next(n) {}
};

// 创建多项式链表（按降幂排列）
PolyNode* createPoly(const int coef[], const int exp[], int n) {
    PolyNode* head = new PolyNode();
    PolyNode* tail = head;
    for (int i = 0; i < n; ++i) {
        tail->next = new PolyNode(coef[i], exp[i]);
        tail = tail->next;
    }
    return head;
}

// 打印多项式
void printPoly(PolyNode* head) {
    PolyNode* cur = head->next;
    bool first = true;
    while (cur) {
        if (!first && cur->coef > 0) cout << "+";
        cout << cur->coef;
        if (cur->exp > 0) cout << "x^" << cur->exp;
        first = false;
        cur = cur->next;
    }
    cout << endl;
}

// 多项式加法（返回新链表）
PolyNode* addPoly(PolyNode* p1, PolyNode* p2) {
    PolyNode* head = new PolyNode();
    PolyNode* tail = head;
    PolyNode *a = p1->next, *b = p2->next;
    while (a && b) {
        if (a->exp > b->exp) {
            tail->next = new PolyNode(a->coef, a->exp);
            a = a->next;
        } else if (a->exp < b->exp) {
            tail->next = new PolyNode(b->coef, b->exp);
            b = b->next;
        } else {
            int sum = a->coef + b->coef;
            if (sum != 0)
                tail->next = new PolyNode(sum, a->exp);
            a = a->next;
            b = b->next;
        }
        if (tail->next) tail = tail->next;
    }
    while (a) {
        tail->next = new PolyNode(a->coef, a->exp);
        tail = tail->next;
        a = a->next;
    }
    while (b) {
        tail->next = new PolyNode(b->coef, b->exp);
        tail = tail->next;
        b = b->next;
    }
    return head;
}

int main() {
    // 多项式1: 3x^4 + 2x^2 + 1
    int coef1[] = {3, 2, 1};
    int exp1[]  = {4, 2, 0};
    PolyNode* poly1 = createPoly(coef1, exp1, 3);
    cout << "P1(x) = ";
    printPoly(poly1);

    // 多项式2: 5x^3 + 2x^2 + 4
    int coef2[] = {5, 2, 4};
    int exp2[]  = {3, 2, 0};
    PolyNode* poly2 = createPoly(coef2, exp2, 3);
    cout << "P2(x) = ";
    printPoly(poly2);

    // 多项式加法
    PolyNode* sum = addPoly(poly1, poly2);
    cout << "P1(x) + P2(x) = ";
    printPoly(sum);

    // 释放内存
    for (PolyNode* cur : {poly1, poly2, sum}) {
        PolyNode* p = cur;
        while (p) {
            PolyNode* tmp = p;
            p = p->next;
            delete tmp;
        }
    }
    return 0;
}
