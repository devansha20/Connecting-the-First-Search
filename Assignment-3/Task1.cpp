#include <iostream>
#include <vector>
#include <string>

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
class dsu_size
{
public:
    vector<int> parent;
    vector<int> size;
    dsu_size(int n)
    {
        parent.resize(n);
        size.resize(n);
        make_sets();
    }
    void make_sets()
    {
        for (int i = 0; i < parent.size(); i++)
        {
            parent[i] = i + 1;
            size[i] = 1;
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
            if (size[a - 1] < size[b - 1])
                swap(a, b);
            parent[b - 1] = a;
            if (size[a - 1] == size[b - 1])
                size[a - 1]++;
        }
    }
};

int main()
{
    int n, t;
    cin >> n >> t;

    // Uncomment/comment the type of union required

    dsu_rank sets(n);
    // dsu_size sets(n);
    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        if (s == "union")
        {
            int a, b;
            cin >> a >> b;
            sets.union_set(a, b);
        }
        else if (s == "get")
        {
            int a, b;
            cin >> a >> b;
            if (sets.isSameSet(a, b))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}