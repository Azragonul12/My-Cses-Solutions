#include<bits/stdc++.h>
using namespace std;
const long long MaxN= 1e6 + 7;
long long dp[MaxN][2];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long tst, n,Mod;
	Mod = 1e9 + 7;
	cin>>tst;
	dp[1][0] = 1;
	dp[1][1] = 1;
	while(tst--){
		cin>>n;
		for(long long i = 2; n >= i; i++){
			dp[i][0] = ((dp[i-1][0] * 2) % Mod) + (dp[i-1][1] % Mod);
			dp[i][1] = ((dp[i-1][1] * 4) % Mod) + (dp[i-1][0] % Mod);
 		}
 		cout<<(dp[n][0] + dp[n][1]) % Mod<<"\n";

	}
}
