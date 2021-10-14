#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Function to detect cycle in an undirected graph.
    bool dfsCycle(int src, vector<bool> &vis, vector<int> adj[], int parent)
    {
        vis[src] = 1;
        for (auto nbr : adj[src])
        {
            if (!vis[nbr])
            {
                if (dfsCycle(nbr, vis, adj, src))
                {
                    return true;
                }
            }
            else if (nbr != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V + 1, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfsCycle(i, vis, adj, -1))
                {
                    return true;
                }
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