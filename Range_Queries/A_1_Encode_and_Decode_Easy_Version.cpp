#include<bits/stdc++.h>
using namespace std;


#define int long long


signed main(){
    string s;
    cin>>s;
    if(s=="first"){
        int n;
        cin>>n;
        string sol= "";
        vector<int>v(n);
        for(int i = 0; i<n;i++){
            cin>>v[i];
            sol.append(1,'a'+v[i]-1);
        }
        cout<<sol<<endl;
    }else{
        string s2;
        cin>>s2;
        cout<<s2.size()<<endl;
        for(int i = 0; i<s2.size();i++){
            int x = s2[i]-'a'+1;
            cout<<x<<" ";
        }cout<<endl;
    }
}