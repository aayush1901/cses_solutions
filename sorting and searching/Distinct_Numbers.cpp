#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    vector<int>v(t);
    set<int>s;
    for(int i =0 ; i<t;i++){
        cin>>v[i];
        s.insert(v[i]);
    }
    cout<<s.size()<<endl;
    
}