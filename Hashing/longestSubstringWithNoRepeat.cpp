#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        int longestUniqueSubsttr(string s)
        {
            if (s.size() <= 1)
                return s.size();
            int ans = -1;
            int i = 0, j = 0;
            unordered_map<char, int> mp;
            while (j < s.size())
            {
                mp[s[j]]++;

                if (j - i + 1 < mp.size())
                    j++;

                else if (j - i + 1 == mp.size())
                {
                    ans = max(j - i + 1, ans);
                    j++;
                }
                else if (j - i + 1 > mp.size())
                {
                    while (j - i + 1 > mp.size())
                    {
                        mp[s[i]]--;
                        if (mp[s[i]] == 0)
                        {
                            mp.erase(s[i]);
                        }
                        i++;
                    }
                    j++;
                }
            }
            return ans;
        }
};

class Solution1
{
    public:
        int longestUniqueSubsttr(string s)
        {
            if(s.length()==0) return 0;
            if(s.length()==1) return 1;
            
            int i=0,j=0;
            vector<int> mp(256,-1);
            int ans=0;
            while(j<s.size()){
                if(mp[s[j]]!=-1){
                    i=max(i,mp[s[j]]+1);
                }
                mp[s[j]]=j;
                ans=max(ans,j-i+1);
                j++;
            }
            return ans;
        }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        Solution1 ob1;
        cout << ob.longestUniqueSubsttr(str) << endl;
        cout << ob1.longestUniqueSubsttr(str) << endl;
    }
    return 0;
}