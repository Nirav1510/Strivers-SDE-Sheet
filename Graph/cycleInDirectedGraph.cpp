#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Function to detect cycle in a directed graph.
    bool dfsCheck(int src, vector<bool> &vis, vector<bool> &stack, vector<int> adj[])
    {
        vis[src] = 1;
        stack[src] = 1;

        for (auto nbr : adj[src])
        {
            if (stack[nbr])
                return 1;
            else if (!vis[nbr])
            {
                if (dfsCheck(nbr, vis, stack, adj))
                {
                    return 1;
                }
            }
        }
        stack[src] = 0;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> vis(V, 0), stack(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfsCheck(i, vis, stack, adj))
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

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}