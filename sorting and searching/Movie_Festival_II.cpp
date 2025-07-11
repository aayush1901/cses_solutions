#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>a(n);
    for(int i = 0; i<n;i++){
        cin>>a[i].first>>a[i].second;
    }

    sort(a.begin(),a.end(),[](pair<int,int>a,pair<int,int>b){
        if(a.second != b.second)
        return a.second<b.second;
        else return a.first<b.first;
    });

   
    multiset<int>m;
    int count = 0;
    for(int i = 0; i<k;i++){
        m.insert(0);
    }


    for(int i = 0; i<n;i++){
        
            auto it = m.upper_bound(a[i].first);
            if(it==m.begin()){
                continue;
            }else{
                it--;
                m.erase(it);
                m.insert(a[i].second);
                count++;

            }

        
        
    }
    cout<<count<<endl;


}