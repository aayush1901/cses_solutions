#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    int n,complete=0;
    cin>>n;vector<int>durations(n),completion(n);
    for(int i = 0; i<n;i++){
        cin>>durations[i];
        cin>>completion[i];
        complete += completion[i];
    }
    sort(durations.begin(),durations.end());
    vector<int>cummulative(n);
    int sum = 0;
    for(int i = 0; i<n;i++){
        sum += durations[i];
        cummulative[i]=sum;
    }

    int finalsum=0;
    for(int i = 0; i<n;i++){
        finalsum += cummulative[i];
       
    }

    cout<<complete-finalsum<<endl;
}