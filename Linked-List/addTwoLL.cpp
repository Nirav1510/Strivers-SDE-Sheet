class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        int carry = 0;

        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;

        while (ptr1 && ptr2)
        {
            int sum = (ptr1->val + ptr2->val + carry);
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);

            tail = tail->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        while (ptr1)
        {
            int sum = ptr1->val + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);

            tail = tail->next;
            ptr1 = ptr1->next;
        }

        while (ptr2)
        {
            int sum = ptr2->val + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);

            tail = tail->next;
            ptr2 = ptr2->next;
        }

        if (carry)
            tail->next = new ListNode(carry);
        return dummy->next;
    }
};

//or

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        int carry = 0, sum = 0;
        while (l1 || l2 || carry)
        {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return dummy->next;
    }
};