#include<bits/stdc++.h>
using namespace std;

// vector<int>prefix(string s){
//     int n = s.size();
//     vector<int>pre(n,0);

//     for(int i = 1; i<n;i++){
//         int j = pre[i-1];

//         while(j>0 && s[i] != s[j]){
//             j = pre[j-1];

//         }

//         if(s[i]== s[j]){
//             j++;
//             pre[i]=j;
//         }
//     }
//     return pre;

// }

vector<int>prefix(string s){
    vector<int>lps(s.size(),0);
    int pre = 0, suff = 1;
    while(suff<s.size()){
        if(s[pre]==s[suff]){
            lps[suff]=pre+1;
            pre++;
            suff++;
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

// int main(){
//     string s;
//     cin>>s;
//     vector<int>arr=prefix(s);
//     int j = s.size()-1;
//     vector<int>v;
    
//     while(j>0){
//         if(arr[j]>0){
//             v.push_back(arr[j]);

//         }
//         j = arr[j]-1;
//     }

//     sort(v.begin(),v.end());
//     for(int i = 0; i<v.size();i++){
//         cout<<v[i]<<" ";
//     }cout<<endl;
    
// }

int main(){
    string s;
    cin>>s;
    vector<int>lps = prefix(s);
    vector<int>sol;
   int k = lps[s.size() - 1];
while (k > 0) {
    sol.push_back(k);
    k = lps[k - 1];
}
    sort(sol.begin(),sol.end());
    for(int i = 0; i<sol.size();i++){
        cout<<sol[i]<<" ";
    }cout<<endl;
}