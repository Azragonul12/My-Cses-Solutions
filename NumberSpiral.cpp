//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<numeric>
#include<utility>
#include<set>
#include<bitset>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long tst, x,y;
	cin>>tst;
	while(tst--){
		cin>>y>>x;
		long long dist;
		if(max(x,y) % 2 == 1){
			dist= abs(max(x,y) - x) + abs(y-1);
		}
		else{
			dist= abs(max(x,y) - y) + abs(x-1);
		}
		cout<<(max(x,y)*max(x,y)) - dist<<"\n";
	}
}


