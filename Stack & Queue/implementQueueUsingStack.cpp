class MyQueue
{
    stack<int> ip, op;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        ip.push(x);
    }

    int pop()
    {
        if (op.empty())
        {
            while (!ip.empty())
            {
                op.push(ip.top());
                ip.pop();
            }
        }
        int ans = op.top();
        op.pop();
        return ans;
    }

    int peek()
    {
        if (op.empty())
            while (ip.size())
            {
                op.push(ip.top());
                ip.pop();
            }
        return op.top();
    }

    bool empty()
    {
        return ip.empty() && op.empty();
    }
};