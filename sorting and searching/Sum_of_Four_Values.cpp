#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x; 
    cin>>n>>x;
    vector<int>arr(n);
    for(int i = 0; i<n;i++)cin>>arr[i];

    vector<int>v=arr;
    sort(v.begin(),v.end());

    int a =-1,b=-1,c=-1,d=-1;

    for(int i = 0; i<n-3;i++){
        a=v[i];
        for(int j = i+1;j<n-2;j++){
            b=v[j];
            int lo = j+1,hi=n-1;
            while(lo<hi){
                if(v[lo]+v[hi]==(x-a-b)){
                    c=v[lo],d=v[hi];
                    break;
                }else if(v[lo]+v[hi]<(x-a-b)){
                    lo++;
                }else{
                    hi--;
                }
            }
            if(c != -1){
                break;
            }
        }
        if(c != -1){
            break;
        }
    }

    if(c==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        int ans1=-1,ans2=-1,ans3=-1,ans4=-1;
        vector<int>finall;
        for(int i = 0;i<n;i++){
            if(arr[i]==a && ans1==-1){
                ans1=a;
                finall.push_back(i+1);
            }
            else if(arr[i]==b && ans2==-1){
                ans2=b;
                finall.push_back(i+1);
            }
            else if(arr[i]==c && ans3==-1){
                ans3=c;
                finall.push_back(i+1);
            }else if(arr[i]==d && ans4==-1){
                ans4=d;
                finall.push_back(i+1);
            }
      
        }

        sort(finall.begin(),finall.end());
        cout<<finall[0]<<" "<<finall[1]<<" "<<finall[2]<<" "<<finall[3]<<endl;

    }
}