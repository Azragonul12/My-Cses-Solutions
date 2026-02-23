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
 
long long cnt[30];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str , ans = "";
	long long n , mx = 0 , fl = 1;
	cin >> str;
	n = str.length();
	for(long long i = 0; n > i; i++){
		cnt[str[i] - 'A']++;
		mx = max(mx , cnt[str[i] - 'A']);
	}
 
	if(mx > ((n + 1) / 2)){
		fl = 0;
	}
	else{
		long long mxn = 0;
		for(long long i = 0; n > i; i++){
			//cout << ans << " ";
			mx = 0;
			mxn = 0;
			for(long long j = 0; ('Z' - 'A') >= j; j++){
				if(mx < cnt[j]){
					mxn = j;
					mx = cnt[j];
				}
			}
			if(mx >= (((n + 2) - i) / 2)){
				ans += (char)('A' + mxn);
				cnt[mxn]--;
			}
			else{
				for(long long j = 0; ('Z' - 'A') >= j; j++){
					if(cnt[j] != 0 && (i == 0 || (j + 'A') != ans[i - 1])){
						cnt[j]--;
						ans += (char)('A' + j);
						j = 50;
					}
				}
			}
		}
 
	}
	if(fl){
		cout << ans;
	}
	else{
		cout << fl - 1;
	}
 
}