#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> LPS(string s){
    vector<int>lps(s.size());
    lps[0]=0;
    int pre = 0,suff=1;
    while(suff<s.size()){
        if(s[pre] == s[suff]){
            lps[suff]= pre+1;
            pre++;
            suff++;
        }else{
            if(pre==0){
                lps[suff]=0;
                suff++;
            }else{
                pre = lps[pre-1];
            }
        }
    }
    return lps;
}

signed main(){
    string s;
    cin>>s;
    vector<int>lps = LPS(s);
    int n = s.size()-1;
    vector<int>sol;
    int pre = n;

    int k = lps[n];
    while (k > 0) {      
    sol.push_back(k);
    k = lps[k - 1];  
    }

   
    // while(lps[pre] != 0){
    //     sol.push_back(lps[pre]);
    //     pre = lps[pre-1];
    // }
    reverse(sol.begin(),sol.end());
    for(int i = 0; i<sol.size();i++){
        cout<<sol[i]<<" ";
    }
}