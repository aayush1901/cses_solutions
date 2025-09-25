#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>v1,vector<int>v2,int n,int m){
    if(n==-1 || m== -1)return 0;

    if(v1[n]==v2[m]){
        return 1+ solve(v1,v2,n-1,m-1);
    }else{
        return max(solve(v1,v2,n-1,m),solve(v1,v2,n,m-1));
    }

}//this was the recursive approach but its nearly impossible to backtrace through this approach the longest subsequence

int solveMem(vector<int>v1,vector<int>v2,int n,int m,vector<vector<int>>&dp){
    
    if(n==0||m==0)return 0;
    if(dp[n][m] != -1)return dp[n][m];

    if(v1[n]==v2[m]){
        return dp[n][m] = 1+ solveMem(v1,v2,n-1,m-1,dp);
    }else{
        return dp[n][m]= max(solveMem(v1,v2,n-1,m,dp),solveMem(v1,v2,n,m-1,dp));
    }


}


void backTrack(vector<vector<int>>&dp,vector<int>a,vector<int>b,int i,int j,vector<int>&v){
    while (i > 0 && j > 0) {
    if (a[i] == b[j]) {
        v.push_back(a[i]);
        i--, j--;
    } else if (dp[i-1][j] > dp[i][j-1]) {
        i--;
    } else {
        j--;
    }
}
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1,0),b(m+1,0);
    for(int i = 1; i<=n;i++){
        cin>>a[i];
    }
    for(int j = 1; j<=m;j++){
        cin>>b[j];
    }

    
    //recursive approach only gives the count of largest subsequence
    // int ans = solve(a,b,a.size()-1,b.size()-1);
    // cout<<ans;

    //memoization
    // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    // int ans = solveMem(a,b,a.size()-1,b.size()-1,dp);
    // cout<<ans<<endl;

    // //backTracking
    // vector<int>v;
    // backTrack(dp,a,b,n,m,v);
    // reverse(v.begin(),v.end());
    // for(auto it : v){
    //     cout<<it<<" ";
    // }cout<<endl;
    //now this is cauusing tle ?? why because overhead stack is causing to slow it down when the max limit that is n=1000 && m==1000 is used..

    //tabulation

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i = 1; i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(a[i]==b[j]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    cout<<dp[n][m]<<endl;
    vector<int>v;
    
    backTrack(dp,a,b,n,m,v);
    reverse(v.begin(),v.end());
    for(auto it : v){
        cout<<it<<" ";
    }cout<<endl;


}