#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// C++ Program to count all subarrays having
// XOR of elements as given value m with
// O(n) time complexity.

long long subarrayXor(vector<int> &A, int B)
{
    ll ans = 0;
    int n = A.size();
    vector<int> xr(n);
    // Create a prefix xor-sum array such that
    // xorArr[i] has value equal to XOR
    // of all elements in arr[0 ..... i]
    xr[0] = A[0];

    for (int i = 1; i < n; i++)
    {
        xr[i] = xr[i - 1] ^ A[i];
    }

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        ll temp = B ^ xr[i];

        if (xr[i] == B)
            ans++;
        // If above XOR exists in map, then there
        // is another previous prefix with same
        // XOR, i.e., there is a subarray ending
        // at i with XOR equal to m.
        if (mp.count(temp))
        {
            ans += mp[temp];
        }

        mp[xr[i]]++;
    }
    return ans;
}

int main()
{
    vector<int> A = {4, 2, 2, 6, 4};
    int B = 6;

    cout << "Number of subarrays having given XOR is "
         << subarrayXor(A, B);
    return 0;
}
