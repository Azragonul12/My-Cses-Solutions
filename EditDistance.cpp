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
const int maxStr = (1e3 * 5 + 5);
long long dp[maxStr][maxStr]; 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str, str1;
	cin>> str >> str1;
	for(long long i=0; str.length() >= i; i++){
		for(long long j= 0; str1.length() >= j; j++){
			int flag = 0;
			if (i != 0 || j != 0) dp[i][j] = 1e9 + 5;
			if(i > 0 && j > 0 && str[i-1] != str1[j-1])	flag = 1;
			if (i > 0 && j > 0){
				dp[i][j] = min(min((dp[i][j-1] + 1) , dp[i-1][j] + 1) , (dp[i-1][j-1]) + flag);
			}
			else{
				if(i>0) dp[i][j] = dp[i-1][j] + 1;
				if(j>0)	dp[i][j] = dp[i][j-1] + 1;
			}

			//cout<<dp[i][j]<<" ";
		}
	}
	cout<<dp[str.length()][str1.length()];
}