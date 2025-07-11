#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int median = v[n / 2]; 

    int total_cost = 0;
    for(int i = 0; i < n; i++) {
        total_cost += abs(v[i] - median);
    }

    cout << total_cost << endl;
}