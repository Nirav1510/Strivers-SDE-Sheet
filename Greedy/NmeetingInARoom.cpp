int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({end[i], {start[i], i}});
    }
    sort(v.begin(), v.end());

    int ans = 1;
    int lastEnd = v[0].first;
    for (int i = 1; i < n; i++)
    {
        if (lastEnd < v[i].second.first)
        {
            ans++;
            lastEnd = v[i].first;
        }
    }
    return ans;
}