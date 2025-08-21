#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&v,int n,int s){
    //base case. this returns 0 if there is no solution also.
    if(s<=0)return 0;

    int ans = INT_MAX;
    for(int i = 0; i<n;i++){
        if(v[i]<=s){
            if(solve(v,n,s-v[i]) != INT_MAX)
            ans = min(ans,1+solve(v,n,s-v[i]));
        }
    }
    return ans;
}

int solve_mem(vector<int>&v,int n,int s,vector<int>&dp){
    //same base case as the recursiove funciton
    if(s<=0)return 0;
    if(dp[s] != INT_MAX)return dp[s];
    
    int ans = INT_MAX;//used to minimize
    for(int i = 0; i<n;i++){
        if(v[i]<=s){
            int k = solve_mem(v,n,s-v[i],dp);
            if(k!= INT_MAX){
                // this if is necessary . suppose there i a number which is not possible to form using the given case then we would have to minimize it.
            ans = min(ans,1+k);
            }
        }
    }
    dp[s]=ans;
    return dp[s];

}

int tabulation(vector<int>&v,int n,int s){

    if(s<=0)return 0;
    vector<int>dp(s+1,INT_MAX);
    dp[0]=0;
    
    for(int i = 1;i<=s;i++){
        for(int j = 0;j<n;j++){
            if(i-v[j]>=0 && dp[i-v[j]] != INT_MAX)
            dp[i]=min(1+dp[i-v[j]],dp[i]);
        }
    }
    return dp[s];
}

// is memory optimization possible? see its not guaranteed that the previously calculated answers will have their dependencies on the upcoming. or which of the previous will have dependency on coming theerefore we would have to keep the track of all. so nno memory optimization.

int main(){
   int n,s;
   cin>>n>>s;
   vector<int>v(n);
   vector<int>dp(s+1,INT_MAX);
   for(int i = 0; i<n;i++){
    cin>>v[i];
   }
   int m = tabulation(v,n,s);
   if(m==INT_MAX){
    cout<<-1<<endl;
   }else{
    cout<<m<<endl;
   }
}