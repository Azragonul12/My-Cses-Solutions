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
	int ar[20];
	for(long long i = 0; k >= i; i++){
		ar[i] = 0;
	}
	piv = 0;
	while(piv < (1 << k)){
		if(piv != 0){
			p = ((piv & (-piv)));
			p = (log2(p) * 1LL);
			//cout << p << ".p ";
			ar[p + 1] = abs(1 - ar[p + 1]);
		}
		for(long long i = 1; k >= i; i++){
			cout << ar[i];
		}
		cout << "\n";
		piv++;
	}
}