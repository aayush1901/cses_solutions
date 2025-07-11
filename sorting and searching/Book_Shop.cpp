#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
        // Go from x to price[i] to avoid overwriting current row
        for (int j = x; j >= price[i]; j--) {
            dp[j] = max(dp[j], pages[i] + dp[j - price[i]]);
        }
    }

    cout << dp[x] << endl;
    return 0;
}c