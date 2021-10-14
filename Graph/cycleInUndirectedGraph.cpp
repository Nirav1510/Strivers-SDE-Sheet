#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Function to detect cycle in an undirected graph.
    bool bfsCycle(int src, vector<bool> &vis, vector<int> adj[])
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int prev = q.front().second;
            q.pop();

            for (auto nbr : adj[node])
            {
                if (!vis[nbr])
                {
                    q.push({nbr, node});
                    vis[nbr] = 1;
                }
                else if (nbr != prev)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> vis(V + 1, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (bfsCycle(i, vis, adj))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}