#include <bits/stdc++.h>
#define N 105
using namespace std;

void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<int> pq;
        for (auto i : arr)
        {
            for (int j : i)
            {
                pq.push(j);
            }
        }
        vector<int> ans(k * k, 0);
        for (int i = k * k - 1; i >= 0; i--)
        {
            ans[i] = pq.top();
            pq.pop();
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
        int k;
        cin >> k;
        vector<vector<int>> arr(N, vector<int>(N, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}