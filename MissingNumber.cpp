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
		cin>>l;
		vector <long long> arr;
		for(long long i=0;l-1>i;i++){
			cin>>d;
			arr.push_back(d);	
		}
		p=1;
		sort(arr.begin(),arr.end());
		for(long long i=0;l>i;i++){
			if(p != arr[i]){
				cout<<p<<" ";
				break;
			}
			p++;
		}
	}
}