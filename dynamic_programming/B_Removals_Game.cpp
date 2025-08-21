#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        bool win = true,win2=true;
        for(int i = 0 ;i<n;i++){
            cin>>a[i];
        }
        for(int i = 0 ;i<n;i++){
            cin>>b[i];
        }
        for(int i = 0 ;i<n;i++){
            if(a[i] != b[i]){
                win =false;
                break;
            }
        }
        if(win){
            cout<<"Bob"<<endl;
        }else{
            reverse(a.begin(),a.end());
            for(int i = 0 ;i<n;i++){
            if(a[i] != b[i]){
                win2 =false;
                break;
            }
        }
        if(win2){
            cout<<"Bob"<<endl;
        }else{
            cout<<"Alice"<<endl;
        }
        }
    }}