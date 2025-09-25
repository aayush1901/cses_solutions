#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007


long long power(long long base,long long exp){
    long long res = 1;
    while(exp>0){
        if(exp & 1)
            res = (res*base)%mod;

        base = (base*base)%mod;
        exp >>= 1;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    long long ans = power(2,n);
    cout<<ans<<endl;
}