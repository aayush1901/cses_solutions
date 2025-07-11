#include<bits/stdc++.h>
using namespace std;


int main(){
   
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>a(n),b(m);

        for(int i = 0; i<n;i++){
            cin>>a[i];
        }

        for(int i = 0; i<m;i++){
            cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        auto s = a.begin(); int ans=0;
for(int i = 0; i < m; i++) {

    auto it = lower_bound(s, a.end(), max(b[i] - k,0));
    if(*it<=b[i]+k && it != a.end()){
        ans++;
        s= it+1;
    }
   
}
cout<<ans<<endl;
    }
