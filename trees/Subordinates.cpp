#include<bits/stdc++.h>
using namespace std;

#define int long long

int dfs(int i,vector<vector<int>>&adj,vector<int>&dp){
    if(adj[i].size()==0)return dp[i]=0;

    if(dp[i] != -1)return dp[i];

    int soln = 0;

    for(int k = 0; k<adj[i].size();k++){
        soln += 1+dfs(adj[i][k],adj,dp);
    }
    soln;
    return dp[i]=soln;
    
}

signed main(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    vector<int>v(n-1);
    for(int i = 0; i<n-1;i++){
        cin>>v[i];
    }
    for(int i = 0; i<n-1;i++){
        adj[v[i]].push_back(i+2);
    }

    vector<int>dp(n+1,-1);
    dfs(1,adj,dp);
    for(int i = 1; i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;

}