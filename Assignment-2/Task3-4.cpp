#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> adj;

void stack_dfs(int s, vector<bool> &visit, stack<int> &stck)
{
    visit[s - 1] = true;
    for (int i = 0; i < adj[s - 1].size(); i++)
    {
        if (visit[adj[s - 1][i] - 1] == false)
            stack_dfs(adj[s - 1][i], visit, stck);
    }
    stck.push(s);
    return;
};

void dfs(int s, vector<int> &visit, vector<vector<int>> trans)
{
    visit[s - 1] = 1;
    for (int i = 0; i < trans[s - 1].size(); i++)
    {
        if (visit[trans[s - 1][i] - 1] == 0)
            dfs(trans[s - 1][i], visit, trans);
    }
    return;
}

vector<vector<int>> transpose(vector<vector<int>> lis)
{
    int n = lis.size();
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < lis[i].size(); j++)
        {
            a[lis[i][j] - 1].push_back(i + 1);
        }
    }
    return a;
}

vector<int> SCC(vector<vector<int>> vec)
{
    adj = vec;
    int n = vec.size();
    vector<bool> visited(n, false);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
            stack_dfs(i + 1, visited, s);
    }
    vector<vector<int>> trans = transpose(vec);

    vector<int> ans(n, 0);
    vector<int> visit(n, 0);
    int k = 0;

    while (!s.empty())
    {
        int a = s.top();
        s.pop();
        if (!visit[a - 1])
        {
            dfs(a, visit, trans);
            k++;
            for (int i = 0; i < n; i++)
            {
                if (visit[i] == 1)
                {
                    visit[i] = 2;
                    ans[i] = k;
                }
            }
        }
    }
    return ans;
}

void twosat(int n, vector<int> a, vector<int> b, vector<char> &c)
{
    int m = a.size();
    vector<vector<int>> vec(n * 2);
    vector<vector<int>> trans(n * 2);
    for (int i = 0; i < m; i++)
    {
        if (a[i] > 0 && b[i] > 0)
        {
            vec[a[i] - 1].push_back(b[i] + n);
            trans[b[i] - 1 + n].push_back(a[i]);
            vec[b[i] - 1].push_back(a[i] + n);
            trans[a[i] - 1 + n].push_back(b[i]);
        }
        else if (a[i] < 0 && b[i] > 0)
        {
            vec[-a[i] - 1 + n].push_back(b[i] + n);
            trans[b[i] - 1 + n].push_back(-a[i] + n);
            vec[b[i] - 1].push_back(-a[i]);
            trans[-a[i] - 1].push_back(b[i]);
        }
        else if (a[i] > 0 && b[i] < 0)
        {
            vec[a[i] - 1].push_back(-b[i] + n);
            trans[-b[i] - 1 + n].push_back(a[i]);
            vec[-b[i] - 1 + n].push_back(a[i] + n);
            trans[a[i] - 1 + n].push_back(-b[i] + n);
        }
        else
        {
            vec[-a[i] - 1 + n].push_back(-b[i]);
            trans[-b[i] - 1].push_back(-a[i] + n);
            vec[-b[i] - 1 + n].push_back(-a[i]);
            trans[-a[i] - 1].push_back(-b[i] + n);
        }
    }
    adj = vec;
    vector<bool> visited(2 * n, false);
    stack<int> s;
    for (int i = 0; i < 2 * n; i++)
    {
        if (visited[i] == false)
            stack_dfs(i + 1, visited, s);
    }
    vector<int> ans(2 * n, 0);
    vector<int> visit(2 * n, 0);
    int k = 0;

    while (!s.empty())
    {
        int a = s.top();
        s.pop();
        if (!visit[a - 1])
        {
            dfs(a, visit, trans);
            k++;
            for (int i = 0; i < 2 * n; i++)
            {
                if (visit[i] == 1)
                {
                    visit[i] = 2;
                    ans[i] = k;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == ans[i + n])
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        else if (ans[i] > ans[i + n])
            c[i] = '-';
        else
            c[i] = '+';
    }
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;
    return;
};

int main()
{
    // Task-3
    //  vector<vector<int>> sample{
    //      {2, 4},
    //      {3},
    //      {1},
    //      {5},
    //      {6},
    //      {4, 7},
    //      {8},
    //      {}};

    // running the SCC decomposition function
    // vector<int> a = SCC(sample);
    // cout << endl
    //      << "The vertex and the respective SCC number:" << endl;
    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    // Task-4
    // int n, m;
    // cin >> m >> n;
    // vector<int> a(m), b(m);
    // vector<char> c(n);
    // for (int i = 0; i < m; i++)
    // {
    //     char c, d;
    //     cin >> c >> a[i];
    //     if (c == '-')
    //         a[i] *= -1;
    //     cin >> d >> b[i];
    //     if (d == '-')
    //         b[i] *= -1;
    // }
    // twosat(n, a, b, c);

    return 0;
}