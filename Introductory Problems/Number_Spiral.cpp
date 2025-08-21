#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;//x==row and y==column
        cin>>x>>y;
        int upper= max(x,y);
        int lower = min(x,y);
        if(upper%2==0){
            if(x==upper){
                cout<<upper*upper - lower + 1<<endl;
            }else{
                cout<<(upper-1)*(upper-1)+lower<<endl;
            }

        }else{
            if(y==upper){
                cout<<upper*upper - lower + 1<<endl;
            }else{
                cout<<(upper-1)*(upper-1)+lower<<endl;
            }
        }
    }
}