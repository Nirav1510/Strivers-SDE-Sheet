ListNode *reverseKGroup(ListNode *A, int B)
{
    ListNode *curr = A, *prev = NULL, *next;
    int count = 0, l = 0;
    while (curr != NULL)
    {
        l++;
        curr = curr->next;
    }
    curr = A;
    if (l < B)
        return A;
    while (count < B && curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next)
    {
        A->next = reverseKGroup(next, B);
    }
    return prev;
}