#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n,sum;
    cin>>n>>sum;
    int count = 0;
    vector<int>a(n);
    vector<pair<int,int>>v;
    int value1= -1,value2=-1;
    for(int i = 0; i<n;i++){
        cin>>a[i];
        v.push_back(make_pair(a[i],i+1));
    }
    sort(v.begin(),v.end());

    int ptr1=0,ptr2=n-1;
    while(ptr1<ptr2){
        if(v[ptr1].first+v[ptr2].first==sum){
            value1=v[ptr1].second;value2=v[ptr2].second;
            break;
        }else if(v[ptr1].first+v[ptr2].first<sum){
            ptr1++;
        }else{
            ptr2--;
        }
    }
    if(value1==-1 && value2==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        cout<<min(value1,value2)<<" "<<max(value1,value2)<<endl;
    }
    


    return 0;
}