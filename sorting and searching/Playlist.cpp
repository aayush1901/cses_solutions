#include<bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin>>n;vector<int>a(n);
   map<int,int>m;
   for(int i = 0; i<n;i++){
    cin>>a[i];
    m[a[i]]=-1;
   }
   vector<int>longest(n);
   longest[0]=0;
   m[a[0]]=0;
   
   for(int i = 1; i<n;i++){
    if(m[a[i]]==-1){
        longest[i]=longest[i-1];
        m[a[i]]=i;
    }else{
        longest[i]=max(m[a[i]]+1,longest[i-1]);
        m[a[i]]=i;
    }
    
   }
   vector<int>output(n);
   for(int i = 0; i<n;i++){
    output[i]=i-longest[i]+1;
   }
   sort(output.rbegin(),output.rend());
   cout<<output[0]<<endl;
}