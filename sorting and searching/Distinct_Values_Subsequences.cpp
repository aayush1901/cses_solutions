#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }
    vector<int>trace(n);
    map<int,int>m;
    for(int i = n-1;i>=0;i--){
        if(m[v[i]]>0){
            trace[i]=m[v[i]];
        }
        m[v[i]]++;
    }
}