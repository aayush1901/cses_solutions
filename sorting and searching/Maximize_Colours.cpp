#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
        
	    vector<int>c(3);
	    for(int i = 0; i<3;i++){
	        cin>>c[i];
	    }
	    sort(c.rbegin(),c.rend());
	    if(c[0]==0)
        {
	        cout<<0<<endl;
	    }
        else if(c[0]==1){
           int  count=0;
            for(int i = 0; i<3;i++){
                if(c[i] != 0){
                    count++;
                }
            }
            cout<<count<<endl;
        }else if(c[0]==2){
            if(c[1]==0){
                cout<<1<<endl;
            }else if(c[1]==1){
                if(c[2]==0){
                    cout<<2<<endl;
                }else{
                    cout<<3<<endl;
                }
            }else{
                if(c[2]==0){
                    cout<<3<<endl;
                }else{
                    cout<<4<<endl;
                }
            }
        }else{
            if(c[1]==0){
                cout<<1<<endl;

            }else if(c[1]==1){
                if(c[2]==0){
                    cout<<2<<endl;
                }else{
                    cout<<3<<endl;
                }
            }else if(c[1]==2){
                if(c[2]==0){
                    cout<<3<<endl;
                }else if(c[2]==1){
                    cout<<4<<endl;
                }else if(c[2]==2){
                    cout<<5<<endl;
                }

            }else{
                if(c[2]==0){
                    cout<<3<<endl;
                }else if(c[2]==1){
                    cout<<4<<endl;
                }else if(c[2]==2){
                    cout<<5<<endl;
                }
                else{
                    cout<<6<<endl;
                }

            }
        }


}}

