#include<bits/stdc++.h>
using namespace std;

#define int long long

#define mod 1000000007

// //a simple approach to solve this problem--
// we need to find ways irrespective of order.. so we would constraint the array to move only from one side.. that means 
// in an array like 1 ,3 , 5 we could each time send the index which tells the function to take all elements from this .
// this woud constraint it to give answer like 1 1 1 1 3 3 and 1 1 3 5 

int solve(vector<int>v,int n,int s, int index){
    //base case
    if(s==0) return 1;
    if(s<0)return 0;

    int ans = 0;
    for(int i = index;i<n;i++){
        int k = solve(v,n,s-v[i],i);
       
        ans = (ans + k) % mod;
    }
    return ans %mod;


}

// again two things two note-- memoization will cause tle and also memory limit of the 2d array could be exhausted.
// i have given this memoization thinking so people would know how we proceed in dp.

int solveMem(vector<int>v,int n,int s,int index,vector<vector<int>>&dp){
    //base case
    if(s==0) return 1;
    if(s<0)return 0;

    if(dp[s][index] != -1) return dp[s][index];

    int ans = 0;
    for(int i = index;i<n;i++){
        int k = solveMem(v,n,s-v[i],i,dp);
       
        ans = ((ans%mod) + (k%mod)) % mod;
    }
    dp[s][index] = ans % mod;
    return dp[s][index];
}

int solveTab(vector<int>&v,int n,int s){
    vector<int>dp(s+1,0);
    ///base case
    dp[0]=1;


    for(int i = 0;i<n;i++){
        for(int j = v[i]; j<=s;j++){
            if(j-v[i]>=0){
                dp[j] = (dp[j]+dp[j-v[i]])%mod;
            }
        }
    }
    return dp[s];
}

/// see the conlusion of this problem-when the problem requires things like selection control(order matters) then in memoization we would require a 2d dp but in tabulation we could do the compression of 2d dp to 1d back by iterating over all choices in required order.
// the only thing which needs to execute this is the change of loop order . as by general extinct we convert the sum ouside and selectors inside but in this case we do the reverse of these loops.

signed main(){
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    
 
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }
    
    int f=solveTab(v,n,x);
    
    cout<<f<<endl;   
    

}