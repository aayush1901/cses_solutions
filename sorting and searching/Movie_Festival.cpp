#include<bits/stdc++.h>
using namespace std;

int main(){  
    
        int n;
        cin>>n;
        vector<pair<int,int>>a;
        for(int i = 0; i<n;i++){
            int x,y;
            cin>>x>>y;
            a.push_back(make_pair(x,y));
            

        }
        sort(a.begin(),a.end(),[](pair<int,int>&u,pair<int,int>&v){
                if(u.second != v.second){
                    return u.second < v.second;
                }
                return u.first > v.first;
            });

       int count =1;
       int current =a[0].second;
       for(int i = 1; i<n;i++){
            if(a[i].first>=current){
                count++;
                current = a[i].second;
            }
       }
       cout<<count<<endl;
    
}