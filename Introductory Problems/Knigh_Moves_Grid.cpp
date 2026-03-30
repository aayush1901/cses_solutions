#include <bits/stdc++.h>
using namespace std;

#define int long long

// wrong answer through this function as i was trying dfs .. the correct answer will come through bfs.

// void solve(int n, vector<vector<int>> &v, int row, int column, int present)
// {

//     if (row >= n || row < 0 || column >= n || column < 0)
//         return;
//     if (v[row][column] == -1)
//     {
//         v[row][column] = present + 1;
//         solve(n, v, row + 2, column + 1, present + 1);
//         solve(n, v, row + 1, column + 2, present + 1);
//         solve(n, v, row + 2, column - 1, present + 1);
//         solve(n, v, row + 1, column - 1, present + 1);
//         solve(n, v, row - 2, column + 1, present + 1);
//         solve(n, v, row - 2, column - 1, present + 1);
//         solve(n, v, row - 1, column + 2, present + 1);
//         solve(n, v, row - 1, column - 2, present + 1);
//     }
//     else
//     {
//         if (v[row][column] > present + 1)
//         {
//             v[row][column] = present + 1;
//             solve(n, v, row + 2, column + 1, present + 1);
//             solve(n, v, row + 1, column + 2, present + 1);
//             solve(n, v, row + 2, column - 1, present + 1);
//             solve(n, v, row + 1, column - 1, present + 1);
//             solve(n, v, row - 2, column + 1, present + 1);
//             solve(n, v, row - 2, column - 1, present + 1);
//             solve(n, v, row - 1, column + 2, present + 1);
//             solve(n, v, row - 1, column - 2, present + 1);
//         }
//     }
// }

signed main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, -1));
    // solve(n, v, 0, 0, -1);

    queue<pair<int, int>> q;
    v[0][0] = 0;
    q.push({0, 0});

    int x = 0, y = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        int arrx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
        int arry[8] = {2, -2, 1, -1, 2, -2, 1, -1};

        for (int i = 0; i < 8; i++)
        {
            int nx = x + arrx[i];
            int ny = y + arry[i];

            if (nx < n && nx >= 0 && ny < n && ny >= 0 && v[nx][ny] == -1)
            {
                v[nx][ny] = v[x][y] + 1;
                q.push({nx, ny});
            }
        }
        q.pop();
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}