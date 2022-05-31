#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;

void dist(int u, int v, vector<int> &a, int k)
{
    if (u == v)
    {
        a.push_back(k);
    }
    for (int i = 0; i < adj[u - 1].size(); i++) // this is equivalent to f(x) = ∑f(y)
    {
        dist(adj[u - 1][i], v, a, k + 1);
    }
    return;
}

int main()
{
    vector<vector<int>> sample{// A sample data-set for adjacency list
                               {2, 4, 3},
                               {6, 11},
                               {5},
                               {6, 10},
                               {10},
                               {8, 12},
                               {6, 8},
                               {9},
                               {},
                               {12},
                               {7},
                               {9}};
    int n = sample.size();
    adj = sample;
    vector<int> a;
    int u, v;
    cout << "Please Enter u v" << endl;
    cin >> u >> v;
    dist(u, v, a, 0);
    sort(a.begin(), a.end());

    cout << "Shortest Path Length: " << a[0] << endl;
    cout << "Longest Path Length: " << a[a.size() - 1] << endl;
    cout << "Number of Paths: " << a.size() << endl;
    return 0;
}