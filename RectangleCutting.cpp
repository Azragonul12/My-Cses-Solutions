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
const int maxN = 507;
long long dp[maxN][maxN];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a,b;
	cin>> a >> b;
	for(long long i = 1; a >= i; i++){
		for(long long j = 1; b >= j; j++){
			dp[i][j] = 1e9 + 7;
			if(i == j)
			{
				dp[i][j] = 0;
				
			}
			for(long long k = 1; j > k; k++){
					dp[i][j] = min(dp[i][j],(dp[i][k] + dp[i][j-k] + 1));
				
			}
			for(long long k = 1; i > k; k++){
				dp[i][j] = min(dp[i][j] , dp[k][j] + dp[i - k][j] + 1);

			}
			//cout << dp[i][j] << " ";
		}
		//cout << "\n";
	}
	
	 cout<<dp[a][b];

}