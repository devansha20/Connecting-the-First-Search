#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> adj;

void top_sort(vector<int> &a, vector<int> degree)
{
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            degree[adj[i][j] - 1]++;
        }
    }
    stack<int> st;
    for (int i = 0; i < degree.size(); i++)
    {
        if (degree[i] == 0)
            st.push(i);
    }
    while (!st.empty())
    {
        int x = st.top();
        a.push_back(x + 1);
        st.pop();
        for (int i = 0; i < adj[x].size(); i++)
        {
            degree[adj[x][i] - 1]--;
            if (degree[adj[x][i] - 1] == 0)
                st.push(adj[x][i] - 1);
        }
    }
    for (int i = 0; i < degree.size(); i++)
        cout << degree[i] << " ";
    cout << endl;
    return;
};

int main()
{
    vector<vector<int>> sample{
        {2, 4, 3},
        {6, 11},
        {5},
        {6, 10},
        {10},
        {7, 8, 12},
        {8},
        {9},
        {},
        {12},
        {7},
        {9}};
    int n = sample.size();
    adj = sample;

    // Task-1: Topological Sort using DFS
    // Verified on CSES:
    // int n, m;
    // cin >> n >> m;
    // vector<vector<int>> sample(n);
    // for (int i = 0; i < m; i++)
    // {
    //     int x, y;
    //     cin >> x >> y;
    //     sample[x - 1].push_back(y);
    // }
    // adj = sample;

    vector<int> a;
    vector<int> degree(n, 0);
    top_sort(a, degree);
    if (a.size() != n)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}