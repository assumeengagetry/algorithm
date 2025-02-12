class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
ListNode* xunihead=new ListNode(0);
xunihead->next=head;
ListNode* current=xunihead;
while(current->next != NULL)
{

    if (current->next->val==val)
    {
       ListNode* tmp=current->next;
        current->next=current->next->next;
        delete tmp;
    }
    else current=current->next;

}