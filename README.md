
// 有品位的版本，消除特例，简单优雅的代码

void remove_list_node(List *list, Node *target)

{
    
    // The "indirect" pointer points to the *address*
    // of the thing we'll update.
    
Node **indirect = &list->head;
    
    // Walk the list, looking for the thing that 
    // points to the node we want to remove.
   
while (*indirect != target)
    indirect = &(*indirect)->next;
*indirect = target->next;
}
