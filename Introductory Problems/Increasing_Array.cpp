#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    // this is a really simple question ... but the only thing this question wants to teach is how we calculate which data type to use.
    // see the value of xi is 10^9 and the value of n is 10^5
    // so whats the worst case scenario?
    // it is any array of form 10^9 0 0 0 0 .... 
    //so we would have to make (n-1)* 10^9 operations which could go upto 10^14 . and limit of int is approx 10^9 so we cant even accomodate 10 such operations. we use long long directly or define our int as long long.
    //when we define int as long long the return type off int main changes to long long .. so we can return some long long number of just chaange type of main function to signed.

    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }

    int ans =0;
    for(int i = 1; i<n;i++){
        if(v[i]<v[i-1]){
            ans += (v[i-1] - v[i]);
            v[i] = v[i-1];// important step otherwise next comparisons will be done through older values of v[i];
        }
    }
    cout<<ans<<endl;
}