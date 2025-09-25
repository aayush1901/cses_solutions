#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i = 0; i<n;i++){
            cin>>v[i];
        }
        int  zeros=0,negativeOne = 0;
        for(int i = 0; i<n;i++){
            if(v[i]==0)zeros++;
            else if(v[i]==-1)negativeOne++;
        }
        int soln = 0;
        soln += zeros;
        if(negativeOne%2==1){
            soln += 2;
        }
        cout<<soln<<endl;
    }
}