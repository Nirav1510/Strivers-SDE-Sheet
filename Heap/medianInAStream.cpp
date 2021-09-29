#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to insert heap.
    priority_queue<double> left;
    priority_queue<double, vector<double>, greater<double>> right;
    void insertHeap(int &x)
    {
        if (left.empty() || x < left.top())
        {
            left.push(x);
        }
        else
        {
            right.push(x);
        }
        balanceHeaps();
    }

    //Function to balance heaps.
    void balanceHeaps()
    {
        if (left.size() > 1 + right.size())
        {
            right.push(left.top());
            left.pop();
        }
        else if (left.size() < right.size())
        {
            left.push(right.top());
            right.pop();
        }
    }

    //Function to return Median.
    double getMedian()
    {
        return left.size() > right.size() ? left.top() : (left.top() + right.top()) / 2;
    }
};

int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
}