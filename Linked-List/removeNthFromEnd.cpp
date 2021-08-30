ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *slow = dummy;
    ListNode *fast = dummy;

    while (n--)
    {
        fast = fast->next;
    }
    if (!fast)
    {
        return head->next;
    }

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    ListNode *todelete = slow->next;
    slow->next = slow->next->next;
    delete (todelete);

    return dummy->next;
}