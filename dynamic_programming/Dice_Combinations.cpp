#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

void solve(int n,int &ans){

    //base condition
    if(n==0){
        ans++;
        return;
    }else if(n<0){
        return;
    }

    //recursive case
    for(int i = 1;i<=6;i++){
        solve(n-i,ans);
    }
}

int solveMem(int n,vector<int>&dp){
    //base condition
    if(n==0){
        return dp[0]=1;
        //optional , this could be mentioned in main also. mentioned here so that we know that its for this case only.

    }

    if(dp[n] != -1){
        return dp[n];
    }

    int ans  = 0;
    for(int i = 1;i<=6;i++){
        if(n-i>=0){
        ans = (ans+solveMem(n-i,dp))%mod;
        }
    }
    dp[n] = ans;
    return dp[n];
}


int solveTab(int n){
    vector<int>dp(n+1,0);

    //base case
    dp[0]=1;
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=6;j++){
            if(i-j>=0){
                dp[i] = (dp[i] + dp[i-j]) % mod;
            }
        }
    }
    return dp[n];
}

// can we do memory optimization?? yes as any numbers present would be dependent only on last 6 places in the tabulation approach, so we try to do it using 6 variables..;
// this might seem tedious but in case of large n, the memory would be optimized and we could use an array of size 6 for this.

int memoryOpti(int n){
    vector<int>tracker(6,0);
    //base case
    tracker[5]=1;

    for(int i = 1; i<=n;i++){
        int ans = 0; 
        for(int j = 1;j<=6;j++){
            ans = (ans + tracker[6-j])%mod;

        }
        for(int i =1;i<6;i++){
            tracker[i-1]=tracker[i];
        }
        tracker[5]=ans;
    }
    return tracker[5];
    // this is the last element of the tracker vector which would give us the answer.
}

signed main(){
    int n;
    cin>>n;
    // int ans = 0;
    // solve(n,ans);
    // cout<<ans;==this is the recursive solution
    
    
//     vector<int>dp(n+1,-1);
//     int ans = solveMem(n,dp);
//     cout<<(ans%mod)<<endl;this solution is for the memoization approach

// int ans = solveTab(n);
// cout<<ans%mod<<endl; // this is the tabulation approach

int ans = memoryOpti(n);
cout<<ans%mod<<endl;
 }