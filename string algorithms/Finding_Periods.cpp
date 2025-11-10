#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int>zmatch(string s){
    vector<int>z(s.size(),0);
    int l = 0,r=0;
    for(int i = 1; i<s.size();i++){
        if(i<r){
            z[i]= z[i-l];

            if(z[i]+i>r){
                z[i]=r-i;
            }
        }

        while(i+z[i]<s.size() && s[z[i]]==s[i+z[i]])z[i]++;

        if(i+z[i]>r){
            l= i;
            r= i+z[i];
        }
    }
    return z;
}


//better approach for solving this problem or writing the z- function ;
vector<int>zmatch(string s){
    int n= s.size();
    vector<int>z(n,0);
    int l = 0,r= 0;
    for(int i = 1;i<n;i++){
        if(i<r){
            z[i]= min(r-i,z[i-l]);
        }
        while(i+z[i])
    }
}

signed main(){
    string s;
    cin>>s;
    vector<int>z = zmatch(s);
    for(int i = 0; i<s.size();i++){
       if(i+z[i]==s.size()){
        cout<<i<<" ";
       }
    }cout<<s.size()<<endl;
}