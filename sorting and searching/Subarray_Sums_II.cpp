#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int &x : v) cin >> x;

    map<long long, int> freq;
    freq[0] = 1; // base case: subarray from index 0

    long long prefix = 0, count = 0;

    for (int i = 0; i < n; i++) {
        prefix += v[i];
        count += freq[prefix - k]; // check if there's a prefix that makes sum=k
        freq[prefix]++;
    }

    cout << count << endl;
}