#include<iostream>
using namespace std;
struct ListNode
{
    int value;
    ListNode* next;
    ListNode(int x):value(x),next(NULL){}
    
};
class myclass
{

private:
ListNode* head;
public:
myclass()
{
    head=new ListNode(0);
}
~myclass()
{
    ListNode* current = head;
    while (current!=NULL)
    {
        ListNode*next = current->next;
        delete current;
        current= next;
    }
}
void charu(int value)
{
    ListNode* newnode = new ListNode(value);
    newnode->next=head->next;
    head->next=newnode; 

}
void shanchu(int value)
{
    ListNode* current=head;
    while(current != NULL)
    {
        if(current->next->value==value)
        {
            ListNode* temp=current->next;
            current->next=current->next->next;
            delete temp;
            return ;
        }
        current =current-> next;

    }
}
void dayinliebiao()
{
    ListNode* current=head-> next;
    while(current != NULL)
    {
        cout<<current->value<<" ";
        current= current -> next;
    }
    cout<<endl;
}
};
int main()
{
    int n,m;cin>>n>>m;
    myclass list;
    for (int i=0;i<n;i++)
    {
        list.charu(i);
    }
    list.shanchu(m);
    list.dayinliebiao();
    return 0; 
}
