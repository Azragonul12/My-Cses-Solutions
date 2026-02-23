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
	long long a,b,c,k,e,l,p,y,lo,n;
	a=1;
	//cin>>a;
	while(a--){
		string kel;
		cin>>kel;
		char d,m;
		n=0;
		p=-1;
		for(long long i=0;kel.length()>i;i++){
			d = kel[i];
 
			if(i != 0){
				if(d != m){
					if(p < n){
						p=n;
					}
					n=1;
				}
				else{
					n++;
				}
			}
			else{
				n++;
			}
			m=d;
		}
		if(p < n){
			p=n;
		}
		n=1;
		cout<<p<<"\n";
	}
}