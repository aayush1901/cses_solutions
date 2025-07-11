#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n;
    cin>>n;
    vector<int>v(n);
    int sum = 0;
    for(int i = 0; i<n;i++){
        cin>>v[i];
        sum+= v[i];
    }
    
    
    sort(v.begin(),v.end());
    int m= v[v.size()-1];
   
    cout<<max(sum,2*m)<<endl;
    
}