 #include<iostream>
 using namespace std;
 
 
 struct listNode
        {
            int val; 
            listNode* next;
            listNode(int val) : val(val),next(NULL){}
        };

class MyLinkedList {
private:
    int _size;
    listNode* dummyhead;
public:
       MyLinkedList()
       {
        dummyhead = new listNode(0);
       _size=0;
       }
    int get(int index) {
    
        if (index > _size -1|| index <0)
        {
            return -1;
        }
        listNode* cur=dummyhead;
        while(index--)
        {
            cur=cur-> next;
        }
         return cur->val;
    }
    
    void addAtHead(int val) {
        listNode* newnode= new listNode(val);
        newnode->next =dummyhead ->next;
        dummyhead->next=newnode->next;
       _size++;
    }
    
    void addAtTail(int val) {
        listNode* newnode =  new listNode(val);
        listNode* current = dummyhead;
while(current->next != NULL)
{
    current = current->next;
}
current->next=newnode;_size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index>_size) return ;
        if (index< 0) index =0 ;
        listNode* newnode= new listNode(val);
        listNode* current=dummyhead;
        while(index--)
        {
            current=current->next;
        }
        newnode-> next=current->next;
        current->next=newnode;
        _size++;}

    void deleteAtIndex(int index) {
        if(index> _size||index<0) return ;
        listNode* current = dummyhead;
        while(index--)
        {
            current = current -> next;
        }
        listNode* temp=current ->next;
        current -> next=current-> next-> next;
        delete temp;temp = NULL;
        _size--;
    }
    void printlistnode()
    {
        listNode* current= dummyhead;
        while(current-> next->val!= NULL )
        {
            cout<<current ->next-> val<<" ";
            current =current-> next;

        }
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