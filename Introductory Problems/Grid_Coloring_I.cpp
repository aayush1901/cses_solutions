#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vector<bool> chars(4, true);
            int remove = v[i][j] - 'A';
            chars[remove] = false;
            if (i - 1 >= 0)
            {
                remove = v[i - 1][j] - 'A';
                chars[remove] = false;
            }
            if (j - 1 >= 0)
            {
                remove = v[i][j - 1] - 'A';
                chars[remove] = false;
            }
            for (int k = 0; k < 4; k++)
            {
                if (chars[k] == true)
                {
                    v[i][j] = char(k + 'A');
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << endl;
    }
}