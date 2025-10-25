#include<bits/stdc++.h>
using namespace std;

// vector<int> prefix_function(string s){
//     int n = s.size();
//     vector<int> pi(n,0);

//     for(int i =1; i<n;i++){
//         int j = pi[i-1];

//         while(j>0 && s[i] != s[j]){
//             j = pi[j-1];
//         }

//         if(s[i]==s[j]){
//             j++;
//             pi[i]=j;
//         }
//     }
//     return pi;
// }
vector<int> prefix_function(string s){
    int pre = 0, suff = 1;
    vector<int>lps(s.size(),0);
    while(suff< s.size()){
        if(s[pre]==s[suff]){
            lps[suff] = pre+1;
            suff++;pre++;
        }else{
            if(pre == 0){
                lps[suff]=0;
                suff++;
            }else{
                pre = lps[pre-1];
            }
        }
    }
    return lps;
}

int main(){
    string s;
    cin>>s;
    int n= s.size();
    string t;
    cin>>t;
    vector<int>lps = prefix_function(t);

//     int j = 0;int cnt=0;
//     for(int i = 0;i<n;i++){
//         while(j>0 && s[i] != t[j]){
//             j=pi[j-1];
//     }
//         if(s[i]== t[j]){
//             j++;
//         }
//         if(j==t.size()){
//             cnt++;
//         }
// }
    int cnt = 0, pre = 0, suff = cnt;
    while(suff<n){
        if(s[suff]==t[pre]){
            suff++;
            pre++;
        }else{
            while(pre>0 && t[pre] != s[suff]){
                pre = lps[pre-1];
            }
            if(s[suff]==t[pre]){
                suff++;
                pre++;
            }else{
                suff++;
            }
        }
        if(pre==t.size()){
            cnt++;
            pre = lps[pre-1];
        }
    }
    cout<<cnt<<endl;
    
    
}