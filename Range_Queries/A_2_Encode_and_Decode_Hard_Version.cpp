#include<bits/stdc++.h>
using namespace std;


#define int long long


signed main(){
    string s;
    cin>>s;
    if(s=="first"){
        int n;
        cin>>n;
        string sol= "";
        int z;
        for(int i = 0; i<n;i++){ 
           cin>>z;
           string p="";
           while(z>0){
           p.append(1,'a'+(z%25));  
           z=z/25; 
           }
           reverse(p.begin(),p.end());
           sol.append(p);           
           sol.append(1,'z');
        }
        cout<<sol<<endl;
    }else{
        string s2;
        cin>>s2;
        vector<int>v;
        int num = 0;
        for(int i = 0 ; i<s2.size();i++){
            if(s2[i]=='z'){
                v.push_back(num);
                num=0;
            }else{
                int temp = s2[i] -'a';
                num = (num*25 + temp);
                
            }   
        }
        
        cout<<v.size()<<endl;
        
        for(int i = 0; i<v.size();i++){
            cout<<v[i]<<" ";
        }cout<<endl;

    }
}