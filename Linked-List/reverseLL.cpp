ListNode *reverseList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *prev = NULL, *curr = head, *nxt;

    while (curr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

// recursive

ListNode *reverseList(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *ans;

    ans = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;
    return ans;
}