#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin>>t;
    vector<int>a(t);
    for(int i = 0; i<t;i++){
        cin>>a[i];
    }
    int maxi = INT_MIN;
    int sum = 0;

    for(int i = 0; i<t;i++){
        if(sum>=0){
            sum+=a[i];
        }else{
            sum = a[i];
        }
        maxi = max(maxi,sum);
    }
    cout<<maxi<<endl;

}