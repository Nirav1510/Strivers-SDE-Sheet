#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    typedef pair<int, int> pii;
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        // Code here
        vector<int> dis(V + 1, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        pq.push({0, s});
        dis[s] = 0;

        while (!pq.empty())
        {
            //int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto nbr : adj[node])
            {
                int next = nbr[0];
                int wt = nbr[1];

                if (dis[next] > dis[node] + wt)
                {
                    dis[next] = dis[node] + wt;
                    pq.push({dis[node], next});
                }
            }
        }
        return dis;
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
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
