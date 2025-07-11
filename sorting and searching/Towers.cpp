#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }
    multiset<int>s;
    s.insert(v[0]);
    for(int i = 1; i<n;i++){
        auto it=s.lower_bound(v[i]);
        if(it==s.end()){
            s.insert(v[i]);
        }else if(*it==v[i]){
            auto my = s.upper_bound(v[i]);
            if(my==s.end()){
                s.insert(v[i]);
            }else{
                s.erase(my);
                s.insert(v[i]);

            }
        }
        else{
            int k = *it;
            s.erase(s.find(k));
            s.insert(v[i]);

        }
        

    }
    cout<<s.size()<<endl;
}