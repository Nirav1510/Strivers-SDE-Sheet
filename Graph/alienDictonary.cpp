void dfs(int node, vector<bool> &vis, vector<int> adj[], stack<int> &s)
{
    vis[node] = 1;

    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfs(nbr, vis, adj, s);
        }
    }
    s.push(node);
}

string findOrder(string dict[], int n, int k)
{
    vector<int> adj[k];

    for (int i = 0; i < n - 1; i++)
    {
        string w1 = dict[i], w2 = dict[i + 1];

        for (int j = 0; j < min(w1.size(), w2.size()); j++)
        {
            if (w1[j] != w2[j])
            {
                adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                break;
            }
        }
    }

    // toposort

    vector<bool> vis(k, 0);
    stack<int> s;

    for (int i = 0; i < k; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, s);
        }
    }

    // ans
    string ans = "";
    while (!s.empty())
    {
        ans += 'a' + s.top();
        s.pop();
    }
    return ans;
}