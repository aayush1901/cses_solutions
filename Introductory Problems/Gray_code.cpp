#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int k = 0;
    vector<string>init;
    init.push_back("");
    
    while(k<n){
        vector<string>temp;
        for(int i = 0;i<init.size();i++){
            temp.push_back("0"+init[i]);
        }

        for(int i = init.size()-1;i>=0;i--){
            temp.push_back("1"+init[i]);
        }
        init = temp;

        k++;
    }
    for(int i = 0; i<init.size();i++){
        cout<<init[i]<<endl;
    }
}