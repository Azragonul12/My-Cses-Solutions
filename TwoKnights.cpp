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
	long long k, piv, count , p;
	count = 0;
	cin>>k;
	piv=2;
	cout<<"0\n"; // Is a special case
	k--;
	while(k--){
		long long ans;
		count = 0;
		ans = (piv * piv);
		ans *= (piv*(piv)*1LL)-1;
		ans /= 2;
		p = 0;
		count += (max(p , (piv - 3) + 1) * max(p , (piv - 2) + 1) * 1LL) * 4;
		cout << ans - count<<"\n";
		piv++;
	}
}