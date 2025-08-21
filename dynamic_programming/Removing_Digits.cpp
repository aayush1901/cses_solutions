#include<bits/stdc++.h>
using namespace std;


#define int long long


//recursive approach- create an array of all digigits present in the number and then check for each digit whose path is shortest to reach 0.
//exponential time complexity.
int solve(int n){
    if(n<10)return 1;

    vector<int>a;
    int k = n;
    while(k>0){
        int d = k% 10;
        a.push_back(d);
        k /= 10;
    }
   
    int ans = INT_MAX;
    for(int i = 0; i<a.size();i++){
        if(a[i]==0)continue;
        ans = min(ans,1+solve(n-a[i]));
    }
    return ans;
    
}

//memoization

int solveMem(int n,vector<int>&dp){
    if(n<10) return dp[n]=1;

    if(dp[n] != -1)return dp[n];

     vector<int>a;
    int k = n;
    while(k>0){
        int d = k% 10;
        a.push_back(d);
        k /= 10;
    }

    int ans = INT_MAX;
    for(int i = 0; i<a.size();i++){
        if(a[i]==0)continue;
        ans = min(ans,1+solveMem(n-a[i],dp));
    }
    dp[n]= ans;
    return dp[n];

}

int SolveTab(int n){
    if(n<10)return 1;
    vector<int>dp(n+1,0);
    for(int i = 1; i<=9;i++){
        dp[i]=1;
    }
    for(int i = 10 ; i<=n;i++){
        vector<int>a;
        int k = i;
        while(k>0){
            int d = k%10;
            a.push_back(d);
            k = (k/10);
        }
        int ans = INT_MAX;
        for(int j = 0; j<a.size();j++){
            if(a[j]==0)continue;
            ans = min(ans,1+dp[i-a[j]]);
        }
        dp[i]=ans;

    }
    return dp[n];
}

//tabulation approach was simple - every digit in 1 to 9 would be sutracted from itself, thereby only return 1. any other digit can check all prevvious digits that can be obtained by subtracting them from itself and there min is the min steps needed to reach that digit.
// time complexity is O(n*log(n)) and space complexity is O(n) for the dp array.
// we didnt consider 0 , ex ---20 - 0 will agaain give 0 resulting in infinite loop.

//now for the MemoryOpti ==> largest digit present in any number ==9 therefore maximum subtraction possible is 9, so we can use a queue??
//NO!! in c++ we cannot call queue by index , so we will use a deque
int memoryOpti(int n){
    if(n<10)return 1;

    deque<int>q;
    for(int i = 1; i<=9;i++){
        q.push_back(1);
    }

    for(int i = 10; i<=n;i++){
        vector<int>a;
        int k = i; 
        while(k>0){
            int d = k%10;
            a.push_back(d);
            k = (k/10);
        }
        int ans  = INT_MAX;
        for(int j = 0; j<a.size();j++){
            if(a[j]==0)continue;
            ans = min(ans,1+q[9-a[j]]);
        }
        q.push_back(ans);
        q.pop_front();
    }
    return q.back();
}



signed main(){
    int n;
    cin>>n;
    //int m = solve(n);
    // vector<int>dp(n+1,-1);
    // int m = solveMem(n,dp);
    int m = memoryOpti(n);
    cout<<m<<endl;
}