//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<utility>
#include<set>
using namespace std;
#define mod 1000000007
int main(){
	ios_base::sync_with_stdio(false);
	long long a,b,c,d,k,e,l,p,y,lo,n,m;
	a=1;
	//cin>>a;
	while(a--){
		cin>>b;
		if(b <= 4){
			if(b!=1 && b!= 4)
			cout<<"NO SOLUTION";
			if(b == 1)
			cout<<"1";
			if(b == 4)
			cout<<"2 4 1 3";
		}
		else{
			p=((b+1)/2);
			p++;
			c=1;
			for(long long i=0;b>i;i++){
				if(i % 2 == 0){
					cout<<c<<" ";
					c++;
				}
				else{
					cout<<p<<" ";
					p++;
				}
			}
		}
	
		
	}
}