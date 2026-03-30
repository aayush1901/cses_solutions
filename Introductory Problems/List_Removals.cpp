#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> seg(10000000);
vector<int> a(1000000);

void build(int idx, int lo, int hi)
{
    if (lo == hi)
    {
        seg[idx] = 1;

        return;
    }
    int mid = (hi + lo) / 2;
    build(2 * idx + 1, lo, mid);
    build(2 * idx + 2, mid + 1, hi);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

void update(int idx, int lo, int hi, int k)
{
    if (lo == hi)
    {
        seg[idx] = 0;
        return;
    }

    int mid = (hi + lo) / 2;
    if (k <= seg[2 * idx + 1])
    {
        update(2 * idx + 1, lo, mid, k);
    }
    else
    {
        update(2 * idx + 2, mid + 1, hi, k - seg[2 * idx + 1]);
    }
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

int query(int idx, int lo, int hi, int k)
{
    if (lo == hi)
    {
        return a[lo];
    }

    int mid = (lo + hi) / 2;

    if (k <= seg[2 * idx + 1])
    {
        return query(2 * idx + 1, lo, mid, k);
    }
    else
    {
        return query(2 * idx + 2, mid + 1, hi, k - seg[2 * idx + 1]);
    }
}

signed main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(0, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        int q;
        cin >> q;
        cout << query(0, 0, n - 1, q) << " ";
        update(0, 0, n - 1, q);
    }
}