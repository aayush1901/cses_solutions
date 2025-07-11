#include <bits/stdc++.h>
using namespace std;

int count_rounds(vector<int>& pos, int n) {
    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1]) rounds++;
    }
    return rounds;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }

    int rounds = count_rounds(pos, n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << rounds << endl;
            continue;
        }

        int x = v[a], y = v[b];

        // Count inversions that will be affected
        int before = 0, after = 0;

        // Check inversions involving x
        if (x > 1 && pos[x - 1] > pos[x]) before++;
        if (x < n && pos[x + 1] < pos[x]) before++;
        // Check inversions involving y
        if (y > 1 && pos[y - 1] > pos[y]) before++;
        if (y < n && pos[y + 1] < pos[y]) before++;
        // If x and y are adjacent in value, we might double-count
        if (abs(x - y) == 1) {
            if ((x < y && pos[x] > pos[y]) || (x > y && pos[y] > pos[x])) before--;
        }

        // Perform the swap
        swap(v[a], v[b]);
        pos[x] = b;
        pos[y] = a;

        // Count new inversions
        if (x > 1 && pos[x - 1] > pos[x]) after++;
        if (x < n && pos[x + 1] < pos[x]) after++;
        if (y > 1 && pos[y - 1] > pos[y]) after++;
        if (y < n && pos[y + 1] < pos[y]) after++;
        if (abs(x - y) == 1) {
            if ((x < y && pos[x] > pos[y]) || (x > y && pos[y] > pos[x])) after--;
        }

        rounds += (after - before);
        cout << rounds << endl;
    }

    return 0;
}