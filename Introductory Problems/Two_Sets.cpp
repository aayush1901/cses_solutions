#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    //if we remember our cllass 10 then we would remember that sum of ap's number form same distance from front and back is same hence if a multiple of 2 pairs exist they are going to be divided ... a little modification with 1 , 2, 3 could show that 4*n-1 would also be ans yes.

    if(n%4==0 || n%4==3){
        cout<<"YES"<<endl;
        long long sum1=0,sum2=0;
        vector<int> set1, set2;

        //for dividing seedhha logic jo peeche ho jaye usko aage kro..
        for(int i =n;i>=1;i--){
            if(sum1<=sum2){
                sum1+=i;
                set1.push_back(i);
            }else{
                sum2+=i;
                set2.push_back(i);
            }
        }
        cout<<set1.size()<<endl;
        for(int i = 0; i < set1.size(); i++){
            cout<<set1[i]<<" ";
        }cout<<endl;
        cout<<set2.size()<<endl;    
        for(int i = 0; i < set2.size(); i++){
            cout<<set2[i]<<" ";
        }cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}