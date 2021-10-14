#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int src, vector<bool> &vis, vector<int> &ans, vector<int> adj[])
    {
        vis[src] = true;
        queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto nbr : adj[node])
            {
                if (!vis[nbr])
                {
                    q.push(nbr);
                    vis[nbr] = true;
                }
            }
        }
    }

    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;
        vector<bool> vis(V + 1, false);
        bfs(0, vis, ans, adj);
        // for(int i=0;i<V;i++){
        //     if(!vis[i])
        //         bfs(i,vis,ans,adj);
        // }
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
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}