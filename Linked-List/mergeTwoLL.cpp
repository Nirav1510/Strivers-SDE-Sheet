ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    ListNode *result;
    if (l1->val < l2->val)
    {
        result = l1;
        result->next = mergeTwoLists(l1->next, l2);
    }
    else
    {
        result = l2;
        result->next = mergeTwoLists(l1, l2->next);
    }
    return result;
}

//iterate

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    //if one of the list is NULL then by default  the other one is our answer
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    // initialise the nodes from head of input lists to traverse them
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    //initialise p3 to store the resultant least
    ListNode *p3 = new ListNode(-1);
    // dummynode will return the ans as p3 at last will be pointing to NULL but dummynode will be pointing head of p3
    ListNode *dummy = p3;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->val > p2->val)
        {
            p3->next = p2;
            p2 = p2->next;
        }
        else
        {
            p3->next = p1;
            p1 = p1->next;
        }
        p3 = p3->next;
    }
    //if p1 is not NULL than all the remaining element of p1 will going to be store in p3
    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;

    } //if p2 is not NULL than all the remaining element of p2 will going to be stored in p3
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummy->next;
}