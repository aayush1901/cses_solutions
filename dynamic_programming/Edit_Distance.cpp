#include<bits/stdc++.h>
using namespace std;

int solve(int n, int m, string &s1, string &s2) {
    if(n== s1.length()){
        return s2.length()-m;
    }
    if(m== s2.length()){
        return s1.length()-n;
    }

    int ans =0;
    if(s1[n]==s2[m]){
        return solve(n+1,m+1,s1,s2);
    }else{
        //insert
        ans = 1+ solve(n,m+1,s1,s2);

        //delete
        ans = min(ans,1+solve(n+1,m,s1,s2));

        //replace
        ans = min(ans,1+solve(n+1,m+1,s1,s2));

        return ans;
    }
}

int solveMem(int i,int j,string&s1,string &s2,vector<vector<int>>&dp){
    if(i== s1.length()){
        return dp[i][j]=s2.length()-j;
    }
    if(j== s2.length()){
        return dp[i][j]=s1.length()-i;
    }
    if(dp[i][j] != -1)return dp[i][j];
    int ans=0;
    if(s1[i]==s2[j]){
        return dp[i][j]=solveMem(i+1,j+1,s1,s2,dp);
    }else{
        //insert
        ans = 1+ solveMem(i,j+1,s1,s2,dp);

        //delete
        ans = min(ans,1+solveMem(i+1,j,s1,s2,dp));

        //replace
        ans = min(ans,1+solveMem(i+1,j+1,s1,s2,dp));
        dp[i][j]=ans;

        return ans;
    }
}

///the approach to tabulation is interesting..... in memoization we used if(i==s1.length()) return s2.length-j; and vice e versa... now this means in any approach if the first iterator on s1 is one some index and other iterator on string s2 reaches the end
//then we need to either delete or add the remaining letters. so this means the condition whene one of the iterator reahes the end we have to consider all remaining condtions on the rest of sstring.
//so we make a row name dp[a.length()][j] for all possible  j less than j reaching the end 
// and similary for the other string;

int solveTab(string&s1, string &s2) {
    vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
    //base case
    for(int j = 0 ;j<s2.length();j++){
        dp[s1.length()][j]=s2.length()-j;
    }
    for(int i = 0; i<s1.length();i++){
        dp[i][s2.length()]=s1.length()-i;
    }

    for(int i = s1.length()-1;i>=0;i--){
        for(int j = s2.length()-1;j>=0;j--){
            int ans = 0; 

            if(s1[i]==s2[j])ans = dp[i+1][j+1];
            else{
                int insert= 1+dp[i][j+1];
                int del = 1+dp[i+1][j];
                int replace = 1+dp[i+1][j+1];
                ans = min(insert,min(del,replace));
            }
            dp[i][j]=ans;
    }
}
return dp[0][0];
}

int memOptimization(string &s1,string &s2){


    vector<int>next(s2.length()+1,0);
    vector<int>curr(s2.length()+1,0);

    //base case -- jo sabse neeche ki row hogi uska hai yeh
    for(int j = 0; j<s2.length();j++){
        next[j]=s2.length()-j;
    }
    for(int i = s1.length()-1;i>=0;i--){
        for(int j = s2.length()-1;j>=0;j--){
            //base case -- jo sabse right most column hogi uska hai yeh for each row..
            curr[s2.length()]=s1.length()-i;

            int ans = 0;

            if(s1[i]==s2[j])ans = next[j+1];
            else{
                int insert = 1+curr[j+1];
                int del = 1+next[j];
                int replace = 1+next[j+1];
                ans = min(insert, min(del, replace));
            }
            curr[j]=ans;
        }
        next = curr; // update next to be the current row for the next iteration
    }
    return next[0];
}


int main(){
    string s1,s2;
    cin>>s1>>s2;

    // int n = s1.length();
    // int m = s2.length();
    // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    // int ans = solveMem(0,0,s1,s2,dp);
    // int ans = solveTab(s1,s2);
    // cout<<ans<<endl;
    int ans = memOptimization(s1,s2);
    cout<<ans<<endl;
    return 0;
}