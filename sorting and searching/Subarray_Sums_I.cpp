#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }
    long long sum = 0,count=0;
    int ptr1=0,ptr2=0;
    sum = v[ptr1];
    while(ptr2<n){
        
        if(sum < m){
            ptr2++;
            sum += v[ptr2];
        }else if(sum>m){
            sum -= v[ptr1];
            ptr1++;
        }else{
            count++;
            sum -=v[ptr1];
            ptr1++;
            ptr2++;
            sum += v[ptr2];
        }

    }
    cout<<count<<endl;
}