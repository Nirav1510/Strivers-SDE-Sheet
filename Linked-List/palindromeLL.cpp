ListNode *reverse(ListNode *head)
{

    ListNode *prev = NULL;
    ListNode *curr = head, *next;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    if (!head->next)
        return true;

    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = reverse(slow);
    fast = head;
    while (slow)
    {
        if (slow->val != fast->val)
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}