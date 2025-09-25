#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    multiset<int>st;
    for(int i = 0; i<n;i++){
        int x;
        cin>>x;
        st.insert(x);
    }
    vector<int>a(m);
    for(int i = 0; i<m;i++){
        cin>>a[i];
        auto it = st.upper_bound(a[i]);
        if(it==st.begin() ){
            cout<<-1<<endl;
        }else if(it == st.end()){
            it--;
            cout<<*it<<endl;
            st.erase(it);
        }else{
      
            it--;
            cout<<*it<<endl;
            st.erase(it);
        
    }
}
}