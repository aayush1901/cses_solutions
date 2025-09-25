#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        map<int,int>mp;
        for(int i = 0; i<n;i++){
            cin>>v[i];
            mp[v[i]]++;
        }
        int required = 0;
        for(int i = 0; i<k;i++){
            if(mp[i] && mp[i]>0){
                continue;
        }else{
            required++;

        }
    }

    if(mp[k] && mp[k]>0){
        if(mp[k]>required){
            required +=  (mp[k]-required);
        }
    }
    cout<<required<<endl;
}
}