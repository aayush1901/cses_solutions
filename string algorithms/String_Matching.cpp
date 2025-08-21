#include<bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> pi(n,0);

    for(int i =1; i<n;i++){
        int j = pi[i-1];

        while(j>0 && s[i] != s[j]){
            j = pi[j-1];
        }

        if(s[i]==s[j]){
            j++;
            pi[i]=j;
        }
    }
    return pi;
}

int main(){
    string s;
    cin>>s;
    int n= s.size();
    string t;
    cin>>t;
    vector<int>pi = prefix_function(t);

    int j = 0;int cnt=0;
    for(int i = 0;i<n;i++){
        while(j>0 && s[i] != t[j]){
            j=pi[j-1];
    }
        if(s[i]== t[j]){
            j++;
        }
        if(j==t.size()){
            cnt++;
        }
}
    cout<<cnt<<endl;
    
    
}