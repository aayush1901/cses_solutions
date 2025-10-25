#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[1000000],seg[4*1000000];

void build(int idx,int lo,int hi){
    if(lo == hi)
    {
        seg[idx]=a[lo];
        return;
    }
    int mid = (lo+hi)/2;
    build(2*idx+1,lo,mid);
    build(2*idx+2,mid+1,hi);
    seg[idx]=seg[2*idx+1]+seg[2*idx+2];
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
    seg[idx]= seg[2*idx+1]+seg[2*idx+2];
}


int query(int idx,int lo,int hi,int l,int r){
    
    if(lo>=l && hi <= r)
    {
        return seg[idx];
    }

    if(lo >r || hi <l)return -1;
    int mid = (lo+hi)/2;

    int sol = 0;

    int left = query(2*idx+1,lo,mid,l,r);

    int right = query(2*idx+2,mid+1,hi,l,r);

    if(left != -1)
    {
        sol += left;
    }

    if(right != -1)
    {
        sol += right;
    }

    return sol;
}

signed main(){
    int n,q;
    cin>>n>>q;
    
    for(int i = 0; i<n;i++)
    {
        cin>>a[i];
    }
    build(0,0,n-1);
    int sign,l,r;

    for(int i=0;i<q;i++)
    {
        cin>>sign>>l>>r;
        if(sign==2){
        cout<<query(0,0,n-1,l-1,r-1)<<endl;
        }else{
            update(0,0,n-1,l-1,r);
        }
    }


}