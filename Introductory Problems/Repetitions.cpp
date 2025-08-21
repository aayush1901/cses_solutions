#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin>>s;


    char prev ='z',present;
    int ans = 0,length =1;
    for(int i = 0; i<s.size();i++){

        present = s[i];
        if(present == prev){
            length++;
        }else{
            length =1;

        }

        ans = max(ans,length);// must learn this, how we check max of our answer in each case if at a beginnner level.
        prev=present;
        
    }
    cout<<ans<<endl;
}