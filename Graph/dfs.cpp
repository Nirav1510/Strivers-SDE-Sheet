#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int src, vector<bool> &vis, vector<int> &ans, vector<int> adj[])
    {
        vis[src] = 1;
        ans.push_back(src);

        for (auto nbr : adj[src])
        {
            if (!vis[nbr])
            {
                dfs(nbr, vis, ans, adj);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;
        vector<bool> vis(V + 1, false);
        dfs(0, vis, ans, adj);
        return ans;
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
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}