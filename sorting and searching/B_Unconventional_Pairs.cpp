#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int count  = 0;
    for(int i = 0; i<n; i = i+2){
        count = max(count,v[i+1]-v[i]);
    }
    cout<<count<<endl;
}
}