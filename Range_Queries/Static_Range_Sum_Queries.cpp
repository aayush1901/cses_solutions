#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t,n;
    cin>>t>>n;
    vector<int>v(t+1);
    v[0]=0;
    for(int i =1; i<=t;i++){
        cin>>v[i];
    }
    vector<int>prefix(t+1);
    int sum = 0;
    for(int i = 0; i<=t;i++){
        sum += v[i];
        prefix[i]=sum;
    }

    int a,b;
    for(int i = 0; i<n;i++){
        cin>>a>>b;
        cout<<prefix[b]-prefix[a-1]<<endl;
    }
    
}