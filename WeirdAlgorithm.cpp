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
	string kel1,kel;
	while(a--){
		cin>>b;
		cout<<b<<" ";
		while(b!= 1){
			if(b % 2 == 0){
				b/=2;
			}
			else{
				b*=3;
				b++;
			}
			cout<<b<<" ";
		}
		
	}
}