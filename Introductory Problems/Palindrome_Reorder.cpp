#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    map<char,int> mp;
    for(auto x:s){
        mp[x]++;
    }
    int count = 0;
    for(auto it : mp){
        if(it.second%2!=0){
            count++;
        }
    }
    if(count>1){
        cout<<"NO SOLUTION"<<endl;
    }
    else{
        string first_half = "", middle = "";
        for(auto it:mp){
            if(it.second%2==0){
                first_half += string(it.second/2, it.first);
            }else{
                first_half += string(it.second/2, it.first);
                middle = string(1, it.first);
            }
        }
        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());
        cout<<first_half + middle + second_half<<endl;
    }
}