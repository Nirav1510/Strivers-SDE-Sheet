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

//or
class MinStack
{
    stack<pair<int, int>> st;

public:
    MinStack(){
        
    }

    void push(int val)
    {
        if (st.empty())
            st.push({val, val});
        else
        {
            int mi = (val < st.top().second) ? val : st.top().second;
            st.push({val, mi});
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};