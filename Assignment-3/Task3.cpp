#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class dsu_rank
{
public:
    vector<int> parent;
    vector<int> rank;
    dsu_rank(int n)
    {
        parent.resize(n);
        rank.resize(n);
        make_sets();
    }
    void make_sets()
    {
        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i + 1;
            rank[i] = 0;
        }
        return;
    }
    int find_parent(int a)
    {
        if (parent[a - 1] == a)
            return a;
        else
            return find_parent(parent[a - 1]);
    }
    bool isSameSet(int a, int b)
    {
        a = find_parent(a);
        b = find_parent(b);
        if (a == b)
            return true;
        else
            return false;
    }
    void union_set(int a, int b)
    {
        a = find_parent(a);
        b = find_parent(b);
        if (a != b)
        {
            if (rank[a - 1] < rank[b - 1])
                swap(a, b);
            parent[b - 1] = a;
            if (rank[a - 1] == rank[b - 1])
                rank[a - 1]++;
        }
    }
};

class edge
{
public:
    int u, v, w;
};

bool compare(edge a, edge b)
{
    return a.w < b.w;
}

int main()
{
    int n, m, weight = 0;
    cin >> n >> m;
    vector<edge> A(m);
    dsu_rank set(n);
    for (int i = 0; i < m; i++)
    {
        cin >> A[i].u >> A[i].v >> A[i].w;
    }
    sort(A.begin(), A.end(), compare);

    for (auto i : A)
    {
        if (set.isSameSet(i.u, i.v) == false)
        {
            weight += i.w;
            set.union_set(i.u, i.v);
        }
    }
    cout << weight;

    return 0;
}