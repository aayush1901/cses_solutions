#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>v(n);
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }
    vector<long long>prefix_sum;

    long long sum = 0;prefix_sum.push_back(sum);
    for(int i = 0; i<n;i++){
        
        sum += v[i];
        prefix_sum.push_back(sum);
    }

    multiset<long long>s,largest_sum;

    for(int i = b;i>=a;i--){
        s.insert(prefix_sum[b-i]);
    }

    long long smallest=*s.begin();
    largest_sum.insert(prefix_sum[b]-smallest);


    for(int i = b+1;i<=n;i++){
  
        auto it = s.find(prefix_sum[i - b - 1]);
         if (it != s.end()) s.erase(it);

        s.insert(prefix_sum[i-a]);
        smallest = *s.begin();
        largest_sum.insert(prefix_sum[i]-smallest);

    }

    auto it = largest_sum.end();it--;
    cout<<*it<<endl;
}