#include<bits/stdc++.h>
using namespace std;

#define int long long


signed main(){
    int n,q;
    cin>>n>>q;
    vector<int>v(n+1);
    v[0]=0;
    int universal_xor = 0;
    for(int i = 1;i<=n;i++){
        int x;
        cin>>x;
        universal_xor = universal_xor^x;
        v[i]=universal_xor;
    }
    for(int i = 0; i<q;i++){
        int a,b;
        cin>>a>>b;
        // cout<<v[a-1]<<" "<<v[b]<<endl;
        cout<<(v[a-1]^v[b])<<endl;
    }
}