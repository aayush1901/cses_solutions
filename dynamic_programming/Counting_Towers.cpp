#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long


// idea ?? 
// if asked in comments or personal dm i would share the resource i used to learn this concept or if needed might also explain this.

//short answer-- think as there are only two way when the height is one eigther two brick or one brick of width =2; then we consider the cases when the bricks may expand to top.. each brick. so 4 cases when upper bricks are  two bricks of width 1 arre used and 1 case of a next brick of width 2 when the lower bricks are of width 1 each. and similarly when lower brick is of width 2 there are 2 cases when uppeb brick is also 2width and one case where upper bricks are of widdth =1;

int solveRec(int n,int i){
    if(n==1)return 1;

    int ans1 = 0;
    ans1 = ans1 + 2*solveRec(n-1,0)%mod+solveRec(n-1,1)%mod;
    int ans2= 0;
    ans2 = ans2 + 4*solveRec(n-1,1)%mod+ solveRec(n-1,0)%mod;

    if(i==0){
        return ans1;
    }else{
        return ans2;
    }

}

int solveMem(int n,int i,vector<vector<int>>&dp){
        if(n==1)return 1;
        if(dp[n][i] != -1)return dp[n][i];

    int ans1 = 0;
    ans1 = (ans1 + 2LL*solveMem(n-1,0,dp)%mod+solveMem(n-1,1,dp)%mod)%mod;
    dp[n][0]=ans1;
    int ans2= 0;
    ans2 = (ans2 + 4LL*solveMem(n-1,1,dp)%mod+ solveMem(n-1,0,dp)%mod)%mod;
    dp[n][1]=ans2;

    if(i==0){
        return dp[n][0];
    }else{
        return dp[n][1];
    }

}

// = 100 and n == 10^6 right... calls kitni so t*n == 10 ^8 right... ab jo call hai.. usme repetitive calls se hamara jo case just pass hona tha... woh stack call time delay se 10^8 se kuch zyada ho gya and case fail.. so best approach would be to use tabulation... 

int solveTab(int n){
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    dp[1][0]=1;dp[1][1]=1;

    for(int i = 2; i<=n;i++){
    int ans1 = 0;
    ans1 = (ans1 + 2LL*dp[i-1][0]%mod+dp[i-1][1]%mod)%mod;
    dp[i][0]=ans1;
    int ans2= 0;
    ans2 = (ans2 + 4LL*dp[i-1][1]%mod+ dp[i-1][0]%mod)%mod;
    dp[i][1]=ans2;

    }
    return (dp[n][0]+dp[n][1])%mod;



}
///solveTab bhi sahi hai... lekin maybe ispr bhi na pass ho-- reason--- as the memory vector gets longer ... even direct accessing of the elements through the index is also not fast enough.. and when we are so close to boundary condition 10^8 it may fail depending upon the test case.
// toh ab hum time limit O(n+t krenge.. :))
// this technique might be used in cp also... where we can precompute and keep the answer within the range and then give answer only depending on the type of input.
//see signed main funcion after the commented one

/*signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // cout<<solveMem(n,0,dp)+solveMem(n,1,dp)<<endl;
        cout<<solveTab(n)<<endl;
    }
}
    */

    vector<vector<int>>dp(1e6+1,vector<int>(2,0));

signed main(){
    dp[1][0]=1;dp[1][1]=1;
       for(int i = 2; i<=1e6;i++){
            int ans1 = 0;
            ans1 = (ans1 + 2LL*dp[i-1][0]%mod+dp[i-1][1]%mod)%mod;
            dp[i][0]=ans1;
            int ans2= 0;
            ans2 = (ans2 + 4LL*dp[i-1][1]%mod+ dp[i-1][0]%mod)%mod;
            dp[i][1]=ans2;
       }
    


    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<(dp[n][1]+dp[n][0])%mod<<endl;
 

    }

    }

    //see some people might solve this in reverse order they may set dp[n][1]==1 and dp[n][0]==1 and then come to dp[1][1] dp[1][0]-- this is very much possible because if we see the building from up or down.. its just another configuration due to symmetricity of rectange.
    //but in that case this pre evaluation is not possible because for each n we have to go from n to 0 and then store the answer.

