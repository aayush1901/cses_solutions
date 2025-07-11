#include<bits/stdc++.h>
using namespace std;

int main(){
    int l,n;
    cin>>l>>n;
    vector<int>v(n);
    for(int i= 0;i<n;i++){
        cin>>v[i];
    }
    set<int>s;
    multiset<int>distances;
    s.insert(l);
    s.insert(0);
    distances.insert(l);
    
    for(int i = 0; i<n;i++){
        auto it = s.upper_bound(v[i]);
        int big= *it;
        
        it--;
        int small = *(it);
       
        distances.erase(distances.find(big-small));
        distances.insert(big - v[i]);
        distances.insert( v[i]-small);
        s.insert(v[i]);
        it = distances.end();it--;
        cout<<*it<<" ";

    }
    cout<<endl;
}