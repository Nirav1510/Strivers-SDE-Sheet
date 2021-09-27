class MyStack
{
    queue<int> q1;
    queue<int> q2;

public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        // if(q1.empty()) return;
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        swap(q1, q2);
        return x;
    }

    /** Get the top element. */
    int top()
    {
        return q1.back();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return !q1.size();
    }
};

// using single queue
class MyStack
{
public:
    queue<int> que;
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        que.push(x);
        for (int i = 0; i < que.size() - 1; ++i)
        {
            que.push(que.front());
            que.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int x = que.front();
        que.pop();
        return x;
    }

    /** Get the top element. */
    int top()
    {
        return que.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return que.size() == 0;
    }
};