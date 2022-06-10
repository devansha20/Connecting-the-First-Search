#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class fen_tree
{
public:
    vector<int> bit;
    int n;
    fen_tree(int a)
    {
        n = a;
        bit.assign(n + 1, 0);
    }
    void add_to_bit(int i, int d)
    {
        for (int j = i; j < n + 1; j += (j & (-j)))
        {
            bit[j] += d;
        }
        return;
    };
    void range_update(int l, int r, int a)
    {
        add_to_bit(l, a);
        add_to_bit(r + 1, -a);
    }
    int point_query(int i)
    {
        int ans = 0;
        for (; i > 0; i -= (i & (-i)))
        {
            ans += bit[i];
        }
        return ans;
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    fen_tree tree(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;
            tree.range_update(a, b, u);
        }
        else
        {
            int k;
            cin >> k;
            cout << v[k - 1] + tree.point_query(k) << endl;
        }
    }
    return 0;
}