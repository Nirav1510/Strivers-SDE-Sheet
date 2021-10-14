#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool check(int node, int parent, int color, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = color;

        for (auto nbr : adj[node])
        {
            if (!vis[nbr])
            {
                if (!(check(nbr, node, 3 - color, vis, adj)))
                {
                    return false;
                }
            }
            else if (nbr != parent && color == vis[nbr])
            {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<int> adj[])
    {

        vector<int> vis(V + 1, 0);
        int color = 1;
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                if (!check(i, -1, color, vis, adj))
                {
                    return false;
                }
            }
        }
        return true;
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
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} 