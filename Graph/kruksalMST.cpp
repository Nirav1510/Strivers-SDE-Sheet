#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    vector<int> parent, rank;
    int find(int n)
    {
        if (parent[n] == -1)
            return n;

        return parent[n] = find(parent[n]);
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> mat(V, vector<int>(V, -1));
        vector<vector<int>> edgeList;
        parent.assign(V, -1);
        rank.assign(V, 1);
        for (int i = 0; i < V; i++)
        {
            for (auto &nbr : adj[i])
            {
                mat[i][nbr[0]] = nbr[1];
            }
        }

        for (int i = 0; i < V; i++)
        {
            for (int j = i; j < V; j++)
            {
                if (mat[i][j] != -1)
                {
                    edgeList.push_back({mat[i][j], i, j});
                }
            }
        }

        sort(edgeList.begin(), edgeList.end());

        int ans = 0;
        for (auto &edge : edgeList)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if (find(x) != find(y))
            {
                unite(x, y);
                ans += w;
            }
        }
        return ans;
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