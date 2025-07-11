#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n);

    for(int i = 0; i<n;i++){
        cin>>v[i];
       
    }
sort(v.begin(),v.end());
    
    long long sum = 0;
    int index = 0;
    
    while(index<n){
        if(v[index]<=(sum+1)){
        sum += v[index];
        }else{
           
            break;
        }
        index++;
    }
    
        cout<<sum+1<<endl;
    


    

}