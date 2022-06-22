#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// This code is incomplete, having trouble with finding all paths

// int ans;

// void f(vector<vector<pair<int, int>>> adj, vector<int> &p, vector<bool> &visit, int depth, int node, vector<int> &path, vector<int> d)
// {
//     int n = adj.size();
//     if (node == n)
//     {
//     }
//     if (visit[node - 1])
//     {
//         if (path[node - 1] > 0)
//         {
//             ans *= 2;
//             int x = node - 1;
//             while (1)
//             {
//                 if (path[x - 1])
//                 {
//                 }
//             }
//         }
//     }
//     visit[node - 1] = true;
//     for (int i = 0; i < adj[node - 1].size(); i++)
//     {
//         int to = adj[node - 1][i].first, cost = adj[node - 1][i].second;
//         if (d[to - 1] == d[node - 1] + cost)
//         {
//             p[to - 1] = node;
//             f(adj, p, visit, depth + 1, to, path, d);
//         }
//     }
// };

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u - 1].push_back({v, cost});
    }

    vector<int> dist(n, 1000000000);
    vector<bool> visit(n, false);
    dist[0] = 0;

    int count = 0, min_edges = n, max_edges = 0;

    for (int i = 0; i < n; i++)
    {
        int a = 0;
        for (int j = 0; j < n; j++)
        {
            if (visit[j] == false)
            {
                if (a == 0)
                    a = j + 1;
                else if (dist[j] < dist[a - 1])
                    a = j + 1;
            }
        }
        visit[a - 1] = true;
        if (dist[a - 1] == 1000000000)
            break;

        for (int j = 0; j < adj[a - 1].size(); j++)
        {
            int to = adj[a - 1][j].first, cost = adj[a - 1][j].second;
            if (dist[to - 1] >= dist[a - 1] + cost)
            {
                dist[to - 1] = dist[a - 1] + cost;
            }
        }
    }
    // vector<int> path(n, 0);
    // vector<int> p(n, -1);
    // vector<bool> v(n, false);
    // p[0] = 1;

    cout << dist[n - 1] << " " << count << " " << min_edges << " " << max_edges << endl;
    return 0;
}