void dfs(int src, vector<bool> &vis, stack<int> &s, vector<int> adj[])
{
    vis[src] = 1;

    for (auto nbr : adj[src])
    {
        if (!vis[nbr])
        {
            dfs(nbr, vis, s, adj);
        }
    }
    s.push(src);
    return;
}

vector<int> topoSort(int V, vector<int> adj[])
{
    stack<int> s;
    vector<bool> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, s, adj);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}