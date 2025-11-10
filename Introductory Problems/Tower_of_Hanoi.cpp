#include<bits/stdc++.h>
using namespace std;

#define int long long

void place(int n, int s, int e){
    if(n==1){
        cout<<s<<" "<<e<<endl;
        return;
    }
    int pos;
    if(s ==1 && e==3 || s ==3 && e == 1){
        pos = 2;
    }else if(s ==2 && e==3 || s ==3 && e == 2){
        pos = 1;
    }else {
        pos =3;
    }
    place(n-1,s,pos);
    cout<<s<<" "<<e<<endl;
    place(n-1,pos,e);

}

signed main(){
    vector<int>points(17,0);
    points[1]=1;
    for(int i = 2;i<=17;i++){
        points[i]=2*points[i-1]+1;
    }
    int n;
    cin>>n;
    cout<<points[n]<<endl;
 
   
    place(n,1,3);
    

}