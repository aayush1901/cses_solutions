#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, ll k) {
    if (n == 1) return 1; // Base case: one child left
    ll half = n / 2;
    if (k <= half) {
        return 2 * k; // k-th even child
    }
    return 2 * solve((n + 1) / 2, k - half) - 1; // Map to odd child in smaller circle
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
    return 0;
}