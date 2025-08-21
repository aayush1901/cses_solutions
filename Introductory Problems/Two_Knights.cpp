#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin>>t;
    cout<<0<<endl;
    if(t>1)cout<<6<<endl;
    for(int n = 3; n <= t; n++){
        cout<<((n*n)*((n*n)-1)/2)-(4*(n-1)*(n-2))<<endl;

        //formula explaination-
        //1 total ways to place 2 knights on n*n board = (n*n)*((n*n)-1)/2
        // now a night can only attack in a block of 2*3 or 3*2 // in indian language we also call it 2.5 moves
        // considering how many 2.5 boxes are there we can make 2*(n-1)*(n-2) (considering both horizaontal and verical boxes) also each box has 2 positions assumingg identical knights otherwise there might be 4 so total becomes 4*(n-1)*(n-2);
    }

}