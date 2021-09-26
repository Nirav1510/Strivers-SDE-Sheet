#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool ispar(string s)
    {
        stack<char> st;
        if (s.size() < 2)
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                    return false;
                char c = st.top();
                if ((s[i] == ')' && c == '(') || (c == '[' && s[i] == ']') || (c == '{' && s[i] == '}'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
}