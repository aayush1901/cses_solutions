#include<bits/stdc++.h>
using namespace std;

#define int long long
// the basic idea i havve implemented after what i understood from document reading.
// int segment_tree(vector<int>&v,int s, int e){
//     if(s==e)return v[s];
//     if(s>e)return -1;
//     int sol  = INT_MAX;
//     int mid = (s+e)/2;

//     sol = min(sol,segment_tree(v,s,mid));
//     sol = min(sol,segment_tree(v,mid+1,e));

//     return sol;
// }

int a[1000000],seg[4*1000000];

void build(int idx, int low, int hi){
    if(low == hi){
        seg[idx] = a[low];
        return;
    }

    int mid = (low+hi)/2;
    build(2*idx+1,low,mid);
    build(2*idx+2,mid+1,hi);

    seg[idx]= min(seg[2*idx+1],seg[2*idx +2]);
}

int query(int idx, int lo , int hi, int l, int r){
    if(lo>=l && hi <=r){
        return seg[idx];
    }
    if(hi < l || lo >r)return INT_MAX;
    int mid = (lo + hi)/2;
    int left = query(2*idx+1,lo,mid,l,r);
    int right = query(2*idx+2,mid+1,hi,l,r);
    return min(left,right);
}

signed main(){
int n,q;
cin>>n>>q;

for(int i = 0; i<n;i++){
    cin>>a[i];
}
build(0,0,n-1);

int x,y;

for(int j = 0; j<q;j++){
    cin>>x>>y;
    cout<<query(0,0,n-1,x-1,y-1)<<endl;
}

}