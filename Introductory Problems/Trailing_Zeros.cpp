#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n;
    cin>>n;
    int cnt = 5;
    int ans = 0;
    ///the number of 5's in the prime factorization of each nummber will give the rright answer;
    while(cnt<=n){
        ans += (n/cnt);
        cnt *= 5;

    }
    cout<<ans<<endl;
}