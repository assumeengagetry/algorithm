#include<iostream>
using namespace std;


struct OLNode{
    int i, j;
    int v;
    OLNode *right;
    OLNode *down;
};

struct CrossList{
    int mu, nu;
    int tu;
    OLNode **rhead;
    OLNode **chead;
    CrossList(int m, int n){
        mu = m;
        nu = n;
        tu = 0;
        rhead = new OLNode*[mu + 1];
        chead = new OLNode*[nu + 1];
        for(int i = 1; i<= mu ;i++){
            rhead[i] = nullptr;
        }
        for(int j = 1; j <= nu; j++){
            chead[j] = nullptr;
        }
    }
    void insert(int i , int j, int v){
        if(v == 0) return ;
        OLNode* p = new OLNode;
        p->i = i;
        p->j = j;
        p->v = v;
        p-> right = nullptr;
        p-> down = nullptr;
        if(!rhead[i] || rhead[i] -> j >j){
            p -> right = rhead[i];
            rhead[i] = p;
        }else{
            OLNode *pre = rhead[i];
            while(pre -> right && pre -> right -> j < j){
                pre = pre -> right;
            }
                p -> right = pre -> right;
                pre -> right = p; 
        }
        if(!chead[j] || chead[j] -> i >i){
            p -> down = chead[j];
            chead[j] = p;
        }else{
            OLNode *pre = chead[j];
            while(pre -> down && pre -> down -> i < i){
                pre = pre -> down;
            }
                p -> down = pre -> down;
                pre -> down = p; 
        }
        ++tu;
    }
    void printtheMatrix() {
        for(int i = 1; i <= mu ; i++){
            OLNode *p = rhead[i];
            int curCol = 1;
            while(curCol <= nu){
                if(p && p->j == curCol){
                    cout << p -> v<< " ";
                    p = p-> right;
                }
                else{
                    cout << 0 << " ";
                }
                ++curCol;
            }
            cout<< "\n";
        }
    }
    ~CrossList(){
        for(int i = 0; i <= mu ; i++){
            OLNode* p = rhead[i];
            while(p){
                OLNode* q = p -> right;
                delete p; 
                p = q;
            }
        }
        delete[] rhead;
        delete[] chead;
    }

};

int main() {
    
    CrossList mat(4, 5);

    mat.insert(1, 2, 5);
    mat.insert(1, 5, 8);
    mat.insert(2, 3, 10);
    mat.insert(3, 1, 7);
    mat.insert(4, 4, 6);
    cout << "Matrix:" << endl;
    mat.printtheMatrix();

    return 0;
}
