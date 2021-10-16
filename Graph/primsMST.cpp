#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

class Solution
{
    public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int cost = 0, src = 0;
        vector<bool> vis(V, 0);
        pq.push({0, src});

        while (!pq.empty())
        {
            pii p = pq.top();
            pq.pop();

            int node = p.second;
            int wt = p.first;

            if (vis[node])
                continue;

            cost += wt;
            vis[node] = 1;

            for (auto &nbr : adj[node])
            {
                if (!vis[nbr[0]])
                {
                    pq.push({nbr[1], nbr[0]});
                }
            }
        }
        return cost;
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}