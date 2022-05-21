#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

// declaring adjacency List, no. of vertices, etc;
vector<vector<int>> adj;
vector<bool> visited;
int n;

vector<int> tin;
vector<int> tout;
vector<int> dist, parent, low;
int dfs_timer = 0;

// DEPTH FIRST SEARCH ------------------------------------------------------------- //
void dfs(int s)
{
    visited[s] = true;
    tin[s] = dfs_timer++;

    for (int i = 0; i < adj[s].size(); i++)
    {
        if (visited[adj[s][i]] == false)
        {
            dfs(adj[s][i]);
            parent[adj[s][i]] = s;
        }
    }
    tout[s] = dfs_timer++;
    return;
};
void edge_checker(int u, int v)
{
    if (abs(tin[u] - tin[v]) != 1) // using enter time to detect edges
        cout << "Back Edge!" << endl;
    else
        cout << "Tree Edge!" << endl;
    return;
};

// BREADTH FIRST SEARCH ---------------------------------------------------------- //

queue<int> q;
int s;

void bfs()
{
    visited[s] = true;
    q.push(s);
    parent[s] = -1;

    while (!q.empty())
    {
        int i = q.front();
        for (int j = 0; j < adj[i].size(); j++)
        {
            int a = adj[i][j];
            if (visited[a] == false)
            {
                visited[a] = true;
                q.push(a);
                dist[a] = dist[i] + 1;
                parent[a] = i;
            }
        }
        q.pop();
    }
    return;
};
void dist_vector(int u)
{
    if (visited[u] == false)
    {
        cout << "-1" << endl;
        return;
    }
    vector<int> path;
    int a = u;
    path.push_back(a);
    while (parent[a] != s)
    {
        path.push_back(parent[a]);
        a = parent[a];
    }
    cout << s;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << "-> " << path[i];
    }
    cout << endl
         << "Distance = " << dist[u] << endl;
    return;
};

vector<int> connected(vector<int> v, vector<bool> used)
{
    int total = 0, k = 1, a = 0;
    while (total != n)
    {
        dfs(a);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == true && v[i] == 0)
            {
                v[i] = k;
                total++;
            }
            if (visited[i] == false && v[i] == 0)
                a = i;
        }
        k++;
        visited = used;
    }
    return v;
}

void cycle(int a)
{
    visited[a] = true;

    for (int i = 0; i < adj[a].size(); i++)
    {
        int b = adj[a][i];
        if (visited[b] && parent[b] != a)
        {
            cout << "Yupp, there is a cycle.." << endl;
            return;
        }
        else if (visited[b] == false)
        {
            dfs(b);
            parent[b] = a;
        }
    }
    if (a == s)
        cout << "No Cycle.." << endl;
    return;
};

void dfs_bridge(int s)
{
    visited[s] = true;
    tin[s] = low[s] = dfs_timer++;

    for (int i = 0; i < adj[s].size(); i++)
    {
        int a = adj[s][i];
        if (parent[s] == a)
            continue;
        else if (visited[a] == true)
        {
            low[s] = min(low[s], tin[a]);
        }
        else
        {
            dfs_bridge(a);
            low[s] = min(low[s], low[a]);
            parent[a] = s;
            if (low[a] > tin[s])
                cout << s << "," << a << " is a bridge" << endl;
        }
    }
    return;
};

// ------------------------------------------------------------------------------------------>

int main()
{

    // using a sample data

    vector<vector<int>> sample{
        {1, 4},
        {0, 4, 2, 3},
        {1, 3},
        {1, 4, 2},
        {3, 0, 1},
        {6},
        {5},
        {8, 9},
        {7, 9},
        {7, 8}};
    adj = sample;

    //---------------------------------------------------------
    // Pass the input to 'adj' here

    n = adj.size();

    vector<bool> s_visited(n, false);
    vector<int> samp(n, 0);
    visited = s_visited, tin = samp, tout = samp, dist = samp, parent = samp, low = samp; // assigning n sized vector with 0 value

    /* Just uncomment whichever task you want to execute and run with appropriate parameters */

    // 1st task- DFS and edge checker
    // parent[s]=-1;
    // dfs(s);
    // edge_checker(u, v);

    // 2nd task- BFS and distance vector
    // s = 0;
    // bfs();
    // dist_vector(5);

    // 3rd task- Connected Components using BFS
    // vector<int> comp;
    // comp = connected(samp, s_visited);
    // for (int i = 0; i < n; i++)
    //     cout << comp[i] << " ";

    // 4th task- Cycle detection using DFS, keep n>=3
    // parent[s] = -1;
    // cycle(s);

    // (Attempt) 5th task- Deleting Bridges using DFS and low value (not giving correct output)
    // parent[0] = -1;
    // dfs_bridge(0);

    return 0;
}