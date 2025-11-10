#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[2*100000],seg[8*100000];

void build(int idx, int s,int e){
    if(s == e){
        seg[idx]= a[s];
        return;
    }
    int mid = (s+e)/2;
    build(2*idx+1,s,mid);
    build(2*idx+2,mid+1,e);
    seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
}

int query(int idx,int range_lo, int range_hi, int lo, int hi){
    if(lo> range_hi || hi < range_lo){
        return INT_MAX;
    }
    if(lo >= range_lo && hi <= range_hi){
        return seg[idx];
    }
    int mid = (lo+hi)/2;
    
    int left = query(2*idx+1, range_lo,range_hi, lo,mid);
    int right = query(2*idx+2,range_lo,range_hi,mid+1,hi);
    return min(left,right);
}

void update(int idx,int lo,int hi,int change,int value){
    if(lo == hi && lo == change){
        seg[idx]=value;
        return;
    }
    int mid = (lo+hi)/2;
    if(change<=mid){
        update(2*idx+1,lo,mid,change,value);
    }else{
        update(2*idx+2,mid+1,hi,change,value);
    }
    seg[idx]= min(seg[2*idx+1],seg[2*idx+2]);
}


signed main(){
    int n,q;
    cin>>n>>q;
    
    for(int i = 0; i<n;i++)cin>>a[i];
    build(0,0,n-1);
    for(int i = 0; i<q;i++){
        int a,b,q;
        cin>>q>>a>>b;
        if(q==1){
            update(0,0,n-1,a-1,b);
        }else{
            cout<<query(0,a-1,b-1,0,n-1)<<endl;;
        }
    }
}