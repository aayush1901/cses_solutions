#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(vector<int>&v,int idx, int &diff,int g1,int g2){
    if(idx == v.size()){
        
        diff = min(diff,abs(g1-g2));
        return;
    }


        solve(v,idx+1,diff,g1+v[idx],g2);
        solve(v,idx+1,diff,g1,g2+v[idx]);

    

}

signed main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }
    
    int diff = INT_MAX;
    solve(v,0,diff,0,0);
    cout<<diff<<endl;
}