#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// TC = o(n) SC = o(1)

class Solution
{
    public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        Node *curr = head;
        while (curr)
        {
            Node *temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }
        curr = head;

        while (curr)
        {
            if (curr->next)
            {
                curr->next->random = curr->random ? curr->random->next : NULL;
            }
            curr = curr->next->next;
        }

        Node *ori = head, *copy = head->next, *ans = copy;
        while (ori)
        {
            ori->next = ori->next->next;
            copy->next = copy->next ? copy->next->next : copy->next;
            ori = ori->next;
            copy = copy->next;
        }
        return ans;
    }
};

// TC = o(n) SC = o(n)

class Solution
{
    public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;
        unordered_map<Node *, Node *> dict;
        Node *res = new Node(head->val);
        Node *cur = head->next;
        Node *preNew = res;
        dict[head] = res;
        while (cur)
        {
            preNew->next = new Node(cur->val);
            dict[cur] = preNew->next;
            preNew = preNew->next;
            cur = cur->next;
        }

        cur = head;
        preNew = res;
        while (cur)
        {
            preNew->random = dict[cur->random];
            cur = cur->next;
            preNew = preNew->next;
        }
        return res;
    }
};