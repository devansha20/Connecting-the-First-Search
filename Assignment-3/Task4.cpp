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
        bit.assign(n, 0);
    }
    void update(vector<int> a)
    {

        vector<int> b(n, 0);
        bit = b;
        for (int i = 0; i < n; i++)
        {
            add_to_bit(i, a[i]);
        }
        return;
    };
    void add_to_bit(int i, int d)
    {
        for (int j = i; j < n; j = (j | (j + 1)))
        {
            bit[j] += d;
        }
        return;
    };
    int sum(int r)
    {
        r--;
        int ans = 0;
        for (; r >= 0; r = ((r & (r + 1)) - 1))
        {
            ans += bit[r];
        }
        return ans;
    }
    int sum_range(int l, int r)
    {
        return sum(r) - sum(l - 1);
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
    tree.update(v);

    for (int i = 0; i < q; i++)
    {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 2)
        {
            cout << tree.sum_range(a, b)
                 << endl;
        }
        else
        {
            v[a - 1] = b;
            tree.update(v);
        }
    }
    return 0;
}