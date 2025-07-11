#include<bits/stdc++.h>
using namespace std;




int main(){      
        int n;
        cin>>n;
        vector<int>a,b;
       map<int,int>m;
        for(int i = 0; i<n;i++){
            int x,y;
            cin>>x>>y;
            a.push_back(x);
            b.push_back(y);
                      
        }

        for(int i = 0; i<n;i++){
            m[a[i]]++;
        }
         for(int i = 0; i<n;i++){
            m[b[i]]--;
        }

        int ans = 1;
        int temp = 0;
        for(auto it :m){
            temp += it.second;
            ans = max(ans,temp);
        }

        cout<<ans<<endl;
        

     
        }


    

