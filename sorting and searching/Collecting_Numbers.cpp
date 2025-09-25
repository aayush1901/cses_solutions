#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin>>n;
    vector<int>v(n);
    for(int i = 0; i<n;i++){
        cin>>v[i];
    }

    set<int>s;int rounds = 1;
   
    
    for(int i = 0; i<n;i++){

        auto it = s.find(v[i]+1);
        if(it!= s.end()){
           
                rounds++;
            

        }
        s.insert(v[i]);
    }
    cout<<rounds<<endl;
    
}