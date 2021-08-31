ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || k == 0 || !head->next)
        return head;

    int l = 1;

    ListNode *tail = head;
    while (tail->next)
    {
        l++;
        tail = tail->next;
    }
    k = k % l;
    k = l - k;
    tail->next = head;
    while (k--)
    {
        tail = tail->next;
    }
    head = tail->next;
    tail->next = NULL;
    return head;
}