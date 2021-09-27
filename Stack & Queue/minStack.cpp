class Solution
{
    int minEle;
    stack<int> s;

public:
    /*returns min element from stack*/
    int getMin()
    {
        return s.empty() ? -1 : minEle;
    }

    /*returns poped element from stack*/
    int pop()
    {
        if (s.empty())
            return -1;
        int ans = s.top();
        s.pop();

        if (ans < minEle)
        {
            minEle = 2 * minEle - ans;
            return (ans + minEle) / 2;
        }
        return ans;
    }

    /*push element x into the stack*/
    void push(int x)
    {
        if (s.empty())
        {
            minEle = x;
            s.push(x);
        }
        else
        {
            if (x >= minEle)
            {
                s.push(x);
            }
            else
            {
                s.push(2 * x - minEle);
                minEle = x;
            }
        }
    }
};