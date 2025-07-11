#include<bits/stdc++.h>
using namespace std;


const long long UNDEF = LLONG_MIN; 

long long solve(vector<int>&v,int s,int e,int turn){
    if(s>=e)return 0;

    long long score1 = 0,score2= 0;


    
    if(turn%2==1){
    score1 += max(v[s]+solve(v,s+1,e,turn+1),v[e]+solve(v,s,e-1,turn+1));
    }else{
       score1 += min(solve(v,s+1,e,turn+1),solve(v,s,e-1,turn+1)); 
    }
    return score1;
}

long long solveMem(vector<int>&v,int s,int e,int turn,vector<vector<long long>>&dp){
    if (s == e) {
    return (turn % 2 == 1 ? v[s] : 0);
}

    //ab dp vector dp[i][j] will denote the maximum score achivable by 

    if(dp[s][e] != UNDEF)return dp[s][e];   

    long long score1 = 0;
     if(turn%2==1){
    score1 += max(v[s]+solveMem(v,s+1,e,turn+1,dp),v[e]+solveMem(v,s,e-1,turn+1,dp));
    }else{
       score1 += min(solveMem(v,s+1,e,turn+1,dp),solveMem(v,s,e-1,turn+1,dp)); 
    }

    dp[s][e]=score1;
    return dp[s][e];

}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    vector<vector<long long>>dp(n,vector<long long>(n,UNDEF));

    for(int i = 0; i<n;i++){
        cin>>v[i];
        
    }
    long long score = solveMem(v,0,n-1,1,dp);
    cout<<score<<endl;
}