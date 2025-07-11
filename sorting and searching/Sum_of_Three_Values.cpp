#include<bits/stdc++.h>
using namespace std;


int binary_search(vector<int>&v,int s, int e,int key){
    int mid = s+(e-s)/2;
    while(s<=e){
        if(v[mid]==key){
            return mid;
        }else if(v[mid]<key){
            s=mid+1;
        }else{
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}



int main(){
   int n,x;
   cin>>n>>x;
   vector<int>arr(n);
   for(int i = 0; i<n;i++){
    cin>>arr[i];
   }
   vector<int>v=arr;

   sort(v.begin(),v.end());
   if(n==1 || n==2)
   {
    cout<<"IMPOSSIBLE"<<endl;
   }

    else{
    int a=-1,b=-1,c=-1;int find = -1;
   for(int i = 0; i<n-2;i++){
    a = v[i];
    for(int j = i+1;j<n-1;j++){
        b=v[j];
        find=binary_search(v,j+1,n-1,x-a-b);
        if(find>-1){
            c = v[find];
            break;
        }
    }
    if(find>-1){
        break;
    }
   }

   if(find>-1){
    int ans1=-1,ans2=-1,ans3=-1;
    vector<int>finall;
   for(int i = 0; i<n;i++){
    
    if(arr[i]==a && ans1==-1){
        ans1=i+1;
        finall.push_back(ans1);
    }else if(arr[i]==b && ans2 ==-1){
        ans2=i+1;
        finall.push_back(ans2);
    }else if(arr[i]==c && ans3==-1){
        ans3=i+1;
        finall.push_back(ans3);
    }

   }
   sort(finall.begin(),finall.end());
   cout<<finall[0]<<" "<<finall[1]<<" "<<finall[2]<<endl;
   }else{
    cout<<"IMPOSSIBLE"<<endl;
   }
}

}