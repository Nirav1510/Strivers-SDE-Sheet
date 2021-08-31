ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
        return nullptr;

    ListNode *a = headA, *b = headB;

    while (a != b)
    {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}
