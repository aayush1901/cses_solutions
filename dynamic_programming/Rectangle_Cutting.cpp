#include<bits/stdc++.h>
using namespace std;

int solveRec(int a,int b){
    if(a==b)return 0;
    int x = min(a,b);
    int y=max(a,b);
    
    int ans = INT_MAX;

    for(int i = 1;i<x;i++){
       
        ans = min(ans,solveRec(x-i,y)+solveRec(i,y));
    }
    for(int j = 1;j<y;j++){
        
        ans = min(ans, solveRec(x,y-j)+solveRec(x,j));
    }
    
    return ans+1;
}

int solveMem(int a,int b,vector<vector<int>>&dp){
    if(a==b){
        dp[a][b]=0;
        return dp[a][b];
    }
    int x = min(a,b);
    int y = max(a,b);
    
    if(dp[x][y] != INT_MAX)return dp[x][y];

    int ans = INT_MAX;

    for(int i = 1;i<x;i++){
       
        ans = min(ans,solveMem(x-i,y,dp)+solveMem(i,y,dp));
    }
    for(int j = 1;j<y;j++){
        
        ans = min(ans, solveMem(x,y-j,dp)+solveMem(x,j,dp));
    }
    dp[x][y]= ans+1;
   
    
    return dp[x][y];
    
}

int solveTab(int a,int b){
    if(a==b)return 0;
    vector<vector<int>>dp(a+1,vector<int>(b+1,0));

    for(int i = 1;i<=a;i++){
        dp[i][i]=0;
    }

    for(int h = 1;h<=a;h++){
        for(int w = 1;w<=b;w++){
            if(h==w)continue;
            int ans = INT_MAX;

            for(int cut = 1; cut<h;cut++){
                ans= min(ans,1+dp[h-cut][w]+dp[cut][w]);
            }
            for(int cut =1; cut<w;cut++){
                ans=min(ans,1+dp[h][w-cut]+dp[h][cut]);
            }
            dp[h][w]=ans;
        }


    }
          return dp[a][b];  

}

int main(){
    int a,b;
    cin>>a>>b;
    vector<vector<int>>dp(max(a,b)+1,vector<int>(max(a,b)+1,INT_MAX));
    int x=solveTab(min(a,b),max(a,b));
    cout<<x<<endl;
}