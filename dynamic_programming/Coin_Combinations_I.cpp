#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int solve_rec(vector<int>&v,int n,int s){
    if(s==0)return 1;
    else if(s<0)return INT_MAX;

    int ans  = 0;
    for(int i = 0; i<n;i++){
        int k = solve_rec(v,n,s-v[i]);
        if(k != INT_MAX)   
        ans  = (ans + k)%mod;

    }
    return ans % mod;
}

//recursive mein bss... logic yeh tha ki jitni baar bhi subtract krte krte 0 pr pahunch skein utne solutions exist krenge.

int solveMem(vector<int>&v,int n,int s,vector<int>&dp){
    if(s==0)return dp[0]=1;
    if(s<0) return INT_MAX;

    if(dp[s] != INT_MAX) return dp[s];

    int ans  = 0;
    for(int i = 0; i<n;i++){
        int k = solve_rec(v,n,s-v[i]);
        if(k != INT_MAX)   
        ans  = (ans + k)%mod;

    }
    dp[s]= ans % mod;
    return dp[s];
    
}
//see the memoization approach is correct but it will fail. reason-- this memoization approach still works on the method of calling a function from out stack which cause some marginal time. 
//and from constraint we see that 100*10^6 are allowed==>10^8 operations .. therefore the stack calling time can cause tle.we use tabulation which does not use a stack memory rather just the array.



int solveTab(vector<int>&v,int n,int s){
   vector<int>dp(s+1,0);
    dp[0]=1;
    for(int i = 1; i<=s;i++){
        for(int j= 0;j<n;j++){
            if(i-v[j]>=0){
                
                    dp[i] = (dp[i]+dp[i-v[j]])%mod;
                
            }
        }
    }
    return dp[s];

}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    // vector<int>dp(x+1,INT_MAX);
    // dp[0]=1;
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }
    
    int f=solveTab(v,n,x);
    
    cout<<f<<endl;
    
    

}