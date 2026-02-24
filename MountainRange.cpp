#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<numeric>
#include <cstring>
#include<utility>
#include<set>
#include<array>
#include<bitset>
using namespace std;
const int nMax = 2e5 + 7;

vector <long long> adj[nMax];
long long dp[nMax];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n , x;
	cin >> n;
	vector <array <long long , 2> > ar;

	array <long long , 2> a;
	stack <long long> st;


	for(long long i = 0; n > i; i++){
		cin >> x;
		a[0] = x;
		a[1] = i;
		ar.push_back(a);
		while(st.size() && ar[st.top()][0] < x){
			st.pop();
		}
		if(st.size()){
			adj[st.top()].push_back(i);
		}
		st.push(i);
	}
	while(st.size()){
		st.pop();
	}
	for(long long i = n - 1; 0 <= i; i--){
		x = ar[i][0];
		while(st.size() && ar[st.top()][0] < x){
			st.pop();
		}
		if(st.size()){
			adj[st.top()].push_back(i);
		}
		st.push(i);
	}
	sort(ar.begin(), ar.end());
	long long mx = 0;
	for(long long i = 0; n > i; i++){
		
		for(long long j = 0; adj[ar[i][1]].size() > j; j++){
			dp[ar[i][1]] = max(dp[ar[i][1]] , dp[adj[ar[i][1]][j]] + 1);
		}
		//cout << dp[ar[i][1]] << " "<< ar[i][0] << " "<< adj[ar[i][1]].size() <<"\n";
		mx = max(mx , dp[ar[i][1]]);
	}
	cout << mx + 1;


	
}