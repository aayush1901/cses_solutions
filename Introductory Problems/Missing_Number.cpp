#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n;
    cin>>n;
    vector<int>arr(n-1);
    for(int i = 0; i<n-1;i++){
        cin>>arr[i];
    }
    

    //method1 -- 
    // sort(arr.begin(),arr.end());
    // for(int i = 0; i<n-1;i++){
    //     if(arr[i] != i+1){
    //         cout<<i+1<<endl;
    //         return 0;
    //     }
    // }

    //method2 --

    int k = accumulate(arr.begin(), arr.end(), 0LL);
    //int k = accumulate(arr.begin(), arr.end(), 0LL) -- must try and see why our code fails without using LL
    //must learn what accumulate does;
    //simply maths formulat sum of first n natural numbers = n*(n+1)/2
    

    cout<<((n*(n+1))/2)-k<<endl;

}