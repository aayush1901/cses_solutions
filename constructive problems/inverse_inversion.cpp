#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n,0);
    int e = n-1;
    int i;

    for(i = 1; i<= n; i++){
        if(k>e){
            v[e]=i;
            k -= e;
            e--;
        }else{
            v[k]= i;
            i++;
            break;
        }
    }
    
    int s = 0;
    while(s<n){
        if(v[s] == 0){
            v[s]= i;
            i++;
        }
        s++;
    }
    for(int i = 0; i<n;i++){
        cout<<v[i]<<" ";
    }
}