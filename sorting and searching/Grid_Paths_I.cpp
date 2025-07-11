#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

void solve(vector<vector<char>>&v,int n,int row,int column,long long &ans){
    if(v[0][0]=='*'|| v[n-1][n-1]=='*')return;

    if(row == n-1 && column ==n-1 ){
        ans++;
        return;
    }

    if(v[row][column] != '*'){
        if(row != n-1)
        solve(v,n,row+1,column,ans);
        if(column != n-1)
        solve(v,n,row,column+1,ans);
    }
    return ;


}


long long solveMem(vector<vector<char>>&v,int n,int row,int column,vector<vector<long long>>&dp){


    if(dp[row][column] != -1)return dp[row][column];
    
    long long ans = 0;
     if(v[row][column] != '*'){
        
        if(row != 0)
        ans = (ans+solveMem(v,n,row-1,column,dp))%mod;
        if(column != 0)
        ans =( ans +solveMem(v,n,row,column-1,dp))%mod;
    }
    dp[row][column]=ans;
    return dp[row][column] ;

}
int main(){
    int n;
    cin>>n;
    vector<vector<char>>arr(n,vector<char>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0; j<n;j++){
            cin>>arr[i][j];
        }
    }
    
    vector<vector<long long>>dp(n,vector<long long>(n,0));
    
    if(arr[0][0]=='*'|| arr[n-1][n-1]=='*'){
        cout<<0<<endl;
        return 0;
    }
    int prev = 1;int current =0;
    vector<int>v(n,0);
    v[0]=1;

    for(int i = 0; i<n;i++){
        prev=0;

        for(int j = 0; j<n;j++){
            current =0;
           
            if(arr[i][j] != '*'){
                if(i>=0){
                    current = (current+ prev)%mod;
                }if(j>=0){
                    current =(current+ v[j])%mod;
                }
                
        }
        v[j]=current;
        prev=current;

        }
    }
    cout<<prev<<endl;;
    return 0;
}