#include<bits/stdc++.h>
using namespace std;

#define int long long


bool possible(vector<int>&v,int mid,int x){
    
    int sum = 0,count = 1;
    for(int i = 0 ; i<v.size();i++){
        if(sum + v[i]<=mid){
            sum +=v[i];
        }
        else{
            count++;
            
            if(count>x || v[i]>mid ){
                return false;
            }
            sum = v[i];
        }

        }
        return true;
}


int solve(vector<int>&v,int s,int e,int slots){
    int mid = s+(e-s)/2;
    int ans = -1;
    while(s<=e){
        if(possible(v,mid,slots)){
            ans = mid;
            e=mid-1;
        }else{
            s=mid+1;
        }

        mid= s+(e-s)/2;
    }
    return ans;
}

signed main(){
    int  n,x;
    cin>>n>>x;
    vector<int>v(n);
    int l=0;
    for(int i = 0; i<n;i++){
        cin>>v[i];
        l+=v[i];
    }
    int sum = solve(v,0,l,x);
    if(sum >-1){
    cout<<sum<<endl;
    }
}