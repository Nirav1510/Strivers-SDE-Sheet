ListNode *detectCycle(ListNode *head)
{
    bool flag = false;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            flag = true;
            break;
        }
    }
    if (!flag)
        return nullptr;

    fast = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}