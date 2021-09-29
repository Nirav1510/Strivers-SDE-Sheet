// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

class Solution
{
public:
    Node *merge(Node *a, Node *b)
    {
        Node *res = NULL;
        if (!a)
            return b;
        if (!b)
            return a;

        if (a->data < b->data)
        {
            res = a;
            res->next = merge(a->next, b);
        }
        else
        {
            res = b;
            res->next = merge(a, b->next);
        }
        return res;
    }

    Node *mergeSort(Node *lists[], int left, int right)
    {
        if (left == right)
            return lists[left];

        int mid = (left + right) / 2;
        Node *l = mergeSort(lists, left, mid);
        Node *r = mergeSort(lists, mid + 1, right);

        return merge(l, r);
    }

    Node *mergeKLists(Node *lists[], int n)
    {
        // Your code here
        if (n == 0)
            return NULL;

        return mergeSort(lists, 0, n - 1);
    }

    // using head
    Node *mergeKLists2(Node *arr[], int n)
    {
        if (n == 0)
            return NULL;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            Node *temp = arr[i];
            while (temp)
            {
                pq.push(temp->data);
                temp = temp->next;
            }
        }
        Node *head = new Node(0);
        Node *dummy = head;
        while (!pq.empty())
        {
            dummy->next = new Node(pq.top());
            pq.pop();
            dummy = dummy->next;
        }
        return head->next;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        Node *ans = obj.mergeKLists2(arr, N);
        printList(res);
        printList(ans);
    }
    return 0;
}