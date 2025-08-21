
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int t;
	cin>>t;
	while(t--){
	    int n,q;
	    cin>>n>>q;
	    string s1,s2;
	    cin>>s1>>s2;
	    bool found1=false,found2=false;
	    int countof1=0,countof2=0;
	    for(int i = 0; i<n;i++){
	        if(s1[i]=='1'){
	            found1=true;
	            countof1++;
	        }
	    }
	    for(int i = 0; i<n;i++){
	        if(s2[i]=='1'){
	            found2=true;
	            countof2++;
	        }
	    }
	    if(found2 && found1){
	        if(countof2+countof1>=n+1){
	            int changepoint = n-countof2;
	            
	            //string s1 mein changepoint ke pehle and tak jitne bhi 0 hain unko unke baad ke 1s se change kro
	            
	            int ans1=0;
	            int ptr1 =changepoint,ptr2=changepoint+1;
	            while(ptr1>=0){
	                if(s1[ptr1]=='0'){
	                    while(s1[ptr2] != '1'){
	                        ptr2++;
	                    }ans1 +=(ptr2-ptr1);
	                    
	                    ptr2++;
	                }
	                ptr1--;
	            }
	            ptr1 = changepoint, ptr2 = changepoint -1;
	            while(ptr1<n){
	                if(s2[ptr1]=='0'){
	                    while(s2[ptr2] != '1'){
	                        ptr2--;
	                    }
	                    ans1 += abs(ptr1-ptr2);
                       
	                    ptr2--;
	                }
	                ptr1++;
	            }

                int ans2= 0;
                changepoint=countof1-1;
                ptr1 =changepoint,ptr2=changepoint+1;
	            while(ptr1>=0){
	                if(s1[ptr1]=='0'){
	                    while(s1[ptr2] != '1'){
	                        ptr2++;
	                    }ans2 +=(ptr2-ptr1);
	                    
	                    ptr2++;
	                }
	                ptr1--;
	            }

                 
	            ptr1 = changepoint, ptr2 = changepoint -1;
	            while(ptr1<n){
	                if(s2[ptr1]=='0'){
	                    while(s2[ptr2] != '1'){
	                        ptr2--;
	                    }
	                    ans2 += abs(ptr1-ptr2);
                       
	                    ptr2--;
	                }
	                ptr1++;
	            }

                int ans3= 0;
                changepoint=n/2;
                ptr1 =changepoint,ptr2=changepoint+1;
	            while(ptr1>=0){
	                if(s1[ptr1]=='0'){
	                    while(s1[ptr2] != '1'){
	                        ptr2++;
	                    }ans3 +=(ptr2-ptr1);
	                    
	                    ptr2++;
	                }
	                ptr1--;
	            }

                 
	            ptr1 = changepoint, ptr2 = changepoint -1;
	            while(ptr1<n){
	                if(s2[ptr1]=='0'){
	                    while(s2[ptr2] != '1'){
	                        ptr2--;
	                    }
	                    ans3 += abs(ptr1-ptr2);                       
	                    ptr2--;
	                }
	                ptr1++;
	            }

cout<<min({ans1,ans2,ans3})<<endl;


	           
	           
	        }
	        
	        else{
	            cout<<-1<<endl;
	        }
	        
	    }else{
	        cout<<-1<<endl;
	    }
	}

}