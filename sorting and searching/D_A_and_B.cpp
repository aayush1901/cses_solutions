#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>a,b;
        for(int i = 0; i<n;i++){
            if(s[i]=='a'){
                a.push_back(i);
            }else{
                b.push_back(i);
            }
        }
        if(a.size()==0 || a.size()==1 || b.size()==0 || b.size()==1){
            cout<<0<<endl;
            continue;
        }
        
        int med_a =a.size()/2;
        int med_b = b.size()/2;
        
        int req_a = 0, req_b = 0;
        for(int i = 1; i+med_a < a.size();i++){
            req_a += abs(a[med_a]+i-a[i+med_a]);
        }
        for(int i = 1; med_a -i >=0; i++){
            req_a += abs(a[med_a]-i - a[med_a - i]);
        }

        for(int i = 1; i+med_b < b.size();i++){
            req_b += abs(b[med_b]+i-b[i+med_b]);
        }
        for(int i = 1; med_b -i >=0; i++){
            req_b += abs(b[med_b]-i - b[med_b - i]);
        }
        cout<<min(req_a,req_b)<<endl;
    }
}