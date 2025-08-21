// User function Template for C++
#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
  
    int solveMem(vector<vector<int>>&mat,int i, int j,int &maxi,vector<vector<int>>&dp){
        if(i>=mat.size() || j>= mat[0].size())return 0;
        
        if(dp[i][j] != -1){
            
            return dp[i][j];
        }
        
        
        
        int right = solveMem(mat,i,j+1,maxi,dp);
        int diagonal = solveMem(mat,i+1,j+1,maxi,dp);
        int down= solveMem(mat,i+1,j,maxi,dp);
        
        if(mat[i][j]==1){
        dp[i][j]=1+min(right,min(down,diagonal));
        
       
        
        maxi=max(maxi,dp[i][j]);
         
       
        return dp[i][j];
        }
        else{
            return dp[i][j]=0;
            
        }
        }
        
    int solveTab(vector<vector<int>>&mat,int &maxi){
        int row = mat.size();
        int column = mat[0].size();
        vector<vector<int>>dp(row,vector<int>(column,0));
        
        for(int i = row-1;i>=0;i--){
            for(int j = column-1;j>=0;j--){
                int right = 0,diagonal= 0,down = 0;
                if(j<column-1)right = dp[i][j+1];
                if(i<row-1)down = dp[i+1][j];
                if(i<row-1 && j<column-1)diagonal = dp[i+1][j+1];
                
                if(mat[i][j]==1){
                    dp[i][j]= 1+min(right,min(diagonal,down));
                    maxi = max(maxi,dp[i][j]);
                    
                }
                
            }
        }
        
        return dp[0][0];
    }
    
    int memoryOpti(vector<vector<int>>&mat,int & maxi){
        int row = mat.size();
        int column = mat[0].size();
        vector<int>prev(mat[0].size(),0);
        
        for(int i = row-1;i>=0;i--){
            vector<int>current(mat[0].size(),0);
            for(int j = column-1;j>=0;j--){
                int right = 0,diagonal= 0,down = 0;
                if(j<column-1)right = current[j+1];
                if(i<row-1)down = prev[j];
                if(i<row-1 && j<column-1)diagonal = prev[j+1];
                
                if(mat[i][j]==1){
                    current[j]= 1+min(right,min(diagonal,down));
                    maxi = max(maxi,current[j]);
                    
                }
                
            }
            prev=current;
        }
        
        return maxi;
    }
    
    
    
    int maxSquare(vector<vector<int>>& mat) {
       
        int maxi = 0;
        int k = memoryOpti(mat,maxi);
        return k;
    }
};