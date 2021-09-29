// O(n) space
typedef pair<int, int> pi;
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> ans;
    priority_queue<pi> pq;
    for (int i : arr)
    {
        int temp = abs(i - x);
        pq.push({temp, i});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// O(1) space
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int i = 0, j = arr.size() - 1;
    while (i + k <= j)
    {
        if (abs(arr[i] - x) > abs(arr[j] - x))
        {
            i++;
        }
        else
            j--;
    }
    vector<int> ans;
    for (int t = i; t < i + k; t++)
    {
        ans.push_back(arr[t]);
    }
    return ans;
}