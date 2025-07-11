#include<bits/stdc++.h>
using namespace std;

#define int long long

bool possible(vector<int>&v,int mid,int x){
    int count =1;int remaining=x;
    for(int i = 0; i<v.size();i++){
         remaining -= (mid / v[i]);
    if (remaining <= 0) return true;
}
        
    
    if(remaining>0)return false;
   
}


int solve(vector<int>&v,int s,int e,int x){
    int mid = s+ (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(possible(v,mid,x)){
            ans = mid;
            e=mid-1;
        }else{
            
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }   
    return s;

}

signed main(){
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());
    int e = v[n-1]*x;
    int ans = solve(v,0,e,x);
    cout<<ans<<endl;
}