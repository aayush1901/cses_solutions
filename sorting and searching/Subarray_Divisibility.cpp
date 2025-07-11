#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n;
    cin>>n;vector<int>v(n);
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }


    vector<long long>prefixes(n);

    long long sum = 0;
    for(int i = 0; i<n;i++){
        sum +=v[i];
        prefixes[i]=sum;
        cout<<prefixes[i]<<" ";
    }cout<<endl;
    map<int,int>m;
    m[0]=1;
    
    long long ans = 0;
    for(int i = 0; i<n;i++){
        int l = abs(prefixes[i] % n);
        m[l]++;
    }

    for(auto it :m){
        ans += (it.second)*(it.second-1)/2;
    }

    cout<<ans<<endl;
}