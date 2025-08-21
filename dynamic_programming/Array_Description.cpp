#include<bits/stdc++.h>
using namespace std;


// i would call it a hardlevel dp question because it took me around to 2-3 hour to build logic for it. and then around same time to implement all its methods.
//the question itself has a lot of constraints which we must check simultaneously while building the logic.


#define int long long
#define mod 1000000007


//what must be the recursive idea here??
// in recursion whenever we reach a case where we have to deal with the array, we have to break down it in smaller subproblem, here we will do it
//by considering only prefix..mtlb --what is the number of ways that the present index could have the number say x ?? we would consider previous cases that how many such previous subarrays can be formed using this idea that they support a particulat number at current index.


int solve(vector<int>&v,int index,int value,int max){
   //base case
   
   if(index==0){
        if(v[index] != 0){
            if(abs(value-v[0])<=1){
                return 1;
            }else{
                return 0;
            }
        }else{
            int ans = 0;
            for(int i =1;i<=max;i++){
                if(abs(value-i)<=1){
                    ans++;
                }
                
            }
            return ans;

        }
   }
   
    //recursive case
   if(v[index] != 0){
        if(abs(value-v[index])<=1){
            return solve(v,index-1,v[index],max);
        }
   }else{
        int ans = 0;
        ans =  (ans +solve(v,index-1,value,max)) % mod;
        if(value>1)ans= (ans + solve(v,index-1,value-1,max))%mod;
        if(value<max)ans= (ans + solve(v,index-1,value+1,max))%mod;
        return ans%mod;
   }

}

// the recursive approach is takin huge time.

int solveMem(vector<int>&v,int index,int value,int max ,vector<vector<int>>&dp){

    if(index==0){
        if(v[index] != 0){
            if(abs(value-v[0])<=1){
                return dp[index][value]=1;
            }else{
                return dp[index][value]=0;
            }
        }else{
            int ans = 0;
            for(int i =1;i<=max;i++){
                if(abs(value-i)<=1){
                    ans++;
                }
                
            }
            return dp[index][value]=ans;

        }
   }
   if(dp[index][value] !=-1)return (dp[index][value])%mod;
   
    //recursive case
   if(v[index] != 0){
        if(abs(value-v[index])<=1){
            return solveMem(v,index-1,v[index],max,dp);
        }
   }else{
        int ans = 0;
        ans = (ans +solveMem(v,index-1,value,max,dp))%mod;
        if(value>1)ans= (ans +solveMem(v,index-1,value-1,max,dp))%mod;
        if(value<max)ans= (ans+ solveMem(v,index-1,value+1,max,dp))%mod;
        return dp[index][value]=ans%mod;
   }
   return 0;

}

// the space is (o(n*m))+stack calling time

int solveTab(vector<int>&v,int max){
    int n = v.size();
    vector<vector<int>>dp(n,vector<int>(max+1,0));

    //base case 
    if(n==1)return (v[0]==0 ? max :1);

    if(v[0] == 0){
        for(int i = 1; i<=max;i++){
            dp[0][i]= 1;
        }
    }else{
        dp[0][v[0]] = 1;
    }

    //calls ?? 

    for(int i = 1; i<n;i++){
        if(v[i] != 0){
            dp[i][v[i]] = (dp[i][v[i]]+dp[i-1][v[i]])%mod;
            if(v[i] > 1) dp[i][v[i]] =(dp[i-1][v[i]-1]%mod+ dp[i][v[i]]%mod)%mod;
            if(v[i] < max) dp[i][v[i]] = (dp[i][v[i]]%mod +dp[i-1][v[i]+1]%mod)%mod;
        }else{
        for(int j = 1; j<=max;j++){
            
            dp[i][j] = (dp[i-1][j-1]%mod+ dp[i-1][j]%mod ) % mod;
            if(j<max) {
                dp[i][j] = (dp[i][j]%mod + dp[i-1][j+1]%mod) % mod;
            }
        }
        

    }

}
if(v[n-1]==0){
    int ans = 0; 
    for(int i =1; i<=max;i++){
        ans = (ans + dp[n-1][i])%mod;
    }
    return ans;
}else{
    return dp[n-1][v[n-1]];
}
}

// still space is O(n*m) and time is O(n*m) but we can optimize it further

// memory optimization ---dhyan se dekhein toh koi bhi value jo at index i aa rhi woh keval prevvious index wali array pr depend kr rhi hai...right?? so agar previous index wali array ko hee hum store kra kr rkh lein toh answer aa jana chahiye ??

int memoryOpti(vector<int>&v,int max){
     int n = v.size();
     vector<int>prev(max+1,0);
    

    //base case 
    if(n==1)return (v[0]==0 ? max :1);

     if(v[0] == 0){
        for(int i = 1; i<=max;i++){
            prev[i]= 1;
        }
    }else{
        prev[v[0]] = 1;
    }
    
    

    for(int i = 1; i<n;i++){
        vector<int>curr(max+1,0);
        if(v[i] != 0){
            curr[v[i]] = (curr[v[i]]+prev[v[i]])%mod;
            if(v[i] > 1) curr[v[i]] =(prev[v[i]-1]%mod+ curr[v[i]]%mod)%mod;
            if(v[i] < max) curr[v[i]] = (curr[v[i]]%mod +prev[v[i]+1]%mod)%mod;
        }else{
        for(int j = 1; j<=max;j++){
            
            curr[j] = (prev[j-1]%mod+ prev[j]%mod ) % mod;
            if(j<max) {
                curr[j] = (curr[j]%mod + prev[j+1]%mod) % mod;
            }
        }
        

    }
    prev=curr;
    

}
if(v[n-1]==0){
    int ans = 0; 
    for(int i =1; i<=max;i++){
        ans = (ans + prev[i])%mod;
    }
    return ans;
}else{
    return prev[v[n-1]];
}

}


signed main(){
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i = 0; i<n;i++)cin>>v[i];
    // vector<vector<int>>dp(n,vector<int>(m+1,-1));

    //  if(n==1){
    //     if(v[0]==0)cout<<m<<endl;
    //     else cout<<1<<endl;
    //     //our code didnt accoutn for n ==1 condition due to which on first run it failed . therfore adding custom check to avoid it.
    //  }else{
    
    // if(v[n-1]==0){
    //     int ans = 0;


    //     for(int i = 1;i<=m;i++){
    //         ans = (ans + solveMem(v,n-2,i,m,dp))%mod;
    //     }
    //     cout<<ans<<endl;
    // }
    // else{
    //     cout<<solveMem(v,n-2,v[n-1],m,dp)<<endl;
    // }
//}

//answer through tabulation
    //cout<<solveTab(v,m)<<endl;

    cout<<memoryOpti(v,m)<<endl;
   
}