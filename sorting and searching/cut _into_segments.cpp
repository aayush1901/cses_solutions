#include<bits/stdc++.h>
using namespace std;

int solve(int n,int x,int y,int z){
	if(n<=0)return 0;
	int maxix=  INT_MIN, maxiy = INT_MIN, maxiz = INT_MIN;
	if(n-x>=0){
 	maxix =1+ solve(n-x,x,y,z);
    }
	if(n-y>=0){
	maxiy=1+ solve(n-y,x,y,z);
	}
	if(n-z>=0){
		maxiz =1+ solve(n-z,x,y,z);
	}

	

	int pass= max({maxix,maxiy,maxiz});
	return pass;
}
int cutSegments(int n, int x, int y, int z) {
	int m = solve(n,x,y,z);
	if(m>0){
	return m;
	}else return 0;

}