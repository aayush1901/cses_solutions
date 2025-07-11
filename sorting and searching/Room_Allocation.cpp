#include <bits/stdc++.h>
using namespace std;

#define int long long

int binary(vector<int>&v,int s,int e,int key){
    int mid = s+ (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(v[mid]>=key){
            ans = mid;
            e= mid-1;
        }else s = mid+1;

        mid = s+ (e-s)/2;
    }return ans;
}

signed main(){
    int n;
    cin>>n;
    vector<int>a(n),d(n);
    vector<pair<int,int>>p;
    
    for(int i = 0; i<n;i++){
        cin>>a[i]>>d[i];
        p.push_back(make_pair(a[i],d[i]));
        
    }

    sort(p.begin(),p.end());

    map<int,int>m;
    for(int i = 0; i<n;i++){
        m[a[i]]++;
        m[d[i]+1]--;
    }

    int together = 0;int sum =0;
    for(auto it :m){
       
        sum += it.second;
        together=max(together,sum);
    }
    cout<<together<<endl;
    
    vector<tuple<int, int ,int>> customers;

    for(int i = 0 ; i<n;i++){
        customers.push_back({a[i],d[i],i});
    }
    sort(customers.begin(),customers.end());

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

    int rooms = 0;vector<int>ans(n);

    for(int i= 0 ; i<n;i++){
        int start = get<0>(customers[i]);
        int end = get<1>(customers[i]);
        int idx = get<2>(customers[i]);


        if(!pq.empty() && start > pq.top().first){
            ans[idx]=pq.top().second;
           
            pq.push(make_pair(end,ans[idx]));
             pq.pop();

            
        }else{
            rooms++;
            pq.push(make_pair(end,rooms));
            ans[idx]=rooms;


        }


        

    }

    for(int i = 0 ;i<n;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;


}