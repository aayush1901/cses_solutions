#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string>v(n);
    for(int i = 0; i<n;i++){
        string s;
        cin>>s;
        v[i]=s;
    }
    vector<vector<string>>dp(n+1,vector<string>(n+1,""));
    string temp = "";
    for(int i = 0; i<n;i++){
        temp.append(1,v[0][i]);
        dp[0][i]=temp;
    }
    temp = "";
    for(int i = 0; i<n;i++){
        temp.append(1,v[i][0]);
        dp[i][0]=temp;
    }

   for(int i = 1;i<n;i++){
    for(int j = 1;j<n;j++){
        string temp1 =dp[i-1][j],temp2=dp[i][j-1];
        string temp;
        int it1=0,it2=0;
        while(it1<temp1.size()&& it2<temp2.size()){
            if(temp1[it1]==temp2[it2]){
                it1++;it2++;
            }else{
                if(temp1[it1]<temp2[it2]){
                    temp = temp1;
                    break;
                }else{
                    temp = temp2;
                    break;
                }
            }
        }
        if(temp.size()==0){
            temp= temp1;
        }
        temp.append(1,v[i][j]);
        dp[i][j]= temp;

    }
   }
   cout<<dp[n-1][n-1]<<endl;

}