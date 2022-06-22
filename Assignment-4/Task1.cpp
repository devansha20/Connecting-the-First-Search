#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
    int u, v, cost;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<edge> E(m);
    vector<int> dist(n, 1000000000);
    vector<int> p(n, -1);
    for (int i = 0; i < m; i++)
    {
        cin >> E[i].u >> E[i].v >> E[i].cost;
    }
    dist[E[0].u - 1] = 0;

    int f = 0;
    for (int i = 0; i < n; i++)
    {
        f = -1;
        for (int j = 0; j < m; j++)
        {
            if (dist[E[j].u - 1] + E[j].cost < dist[E[j].v - 1])
            {
                dist[E[j].v - 1] = dist[E[j].u - 1] + E[j].cost;
                p[E[j].v - 1] = E[j].u;
                f = E[j].v;
            }
        }
    }
    if (f == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
            f = p[f - 1];

        vector<int> cycle;
        int x = 0;
        for (int i = f;; i = p[i - 1])
        {
            cycle.push_back(i);
            x++;
            if (i == f && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES" << endl;
        for (int i = 0; i < x; i++)
            cout << cycle[i] << " ";
    }
    return 0;
}