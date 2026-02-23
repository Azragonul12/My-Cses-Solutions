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
		vector <long long> arr;
		n=0;
		p=0;
		for(long long i=0;b>i;i++){
			cin>>l;
			if(i != 0){
				if(m > l){
					p+=(m-l);
					l= m;
				}
				
			}
			m=l;
		}
		if(m > l){
			p+=(m-l);
		}
		cout<<p<<"\n";
	
		
	}
}