#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    deque<int>v(n);
    for(int i = 0; i<n;i++){
        v[i]=i+1;
    }
    while(v.size()>1){
        int k = v[0];
        v.pop_front();
        cout<<v[0]<<" ";
        v.pop_front();
        v.push_back(k);
    }
    cout<<v[0]<<endl;
}