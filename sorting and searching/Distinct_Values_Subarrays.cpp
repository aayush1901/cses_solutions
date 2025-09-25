#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int>v(n+1);
    for(int i = 1;i<=n;i++){
        cin>>v[i];
    }
    vector<int>dp(n+1,0);
    map<int,int>m;
    for(int i = 1 ; i<=n;i++){
        if(m.find(v[i])==m.end()){
            dp[i]=0;
        }else{
            dp[i]=m[v[i]];
        }
        m[v[i]]=i;
    }

    long long sum = 0;
    int s = 0;
    for(int i = 1;i<=n;i++){
        if(dp[i]>s){
            s=dp[i];
        }
        sum += (i-s);
    }
    cout<<sum<<endl;

    return 0;

}