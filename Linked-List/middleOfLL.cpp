ListNode *middleNode(ListNode *head)
{
    if (head == NULL)
        return NULL;

    ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//or

ListNode *middleNode(ListNode *head)
{
    ListNode *tmp = head;
    int c = 0;

    while (tmp)
        tmp = tmp->next, ++c;

    tmp = head;
    c /= 2;
    while (c > 0)
        tmp = tmp->next, --c;

    return tmp;
}