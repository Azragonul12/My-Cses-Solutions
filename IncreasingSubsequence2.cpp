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
#include<unordered_map>
using namespace std;
const int nMax = 2e5 + 7;
const int mod = 1e9 + 7;
long long fenwick[nMax];
long long n;
void upd(long long num , long long val){
	for(long long i = num; n >= i; i += (i & -i)){
		fenwick[i] += val;
	}
}
long long search(long long num){
	long long ans = 0;
	for(long long i = num; 0 < i; i -= (i & -i)){
		ans += fenwick[i];
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long m , x;
	cin >> n;
	vector <long long> ar;
	vector <long long> com;
	unordered_map <long long , long long> comp;
	for(long long i = 0; n > i; i++){
		cin >> x;
		ar.push_back(x);
		com.push_back(x);
	}
	sort(com.begin(), com.end());
	long long piv = 1;
	for(long long i = 0; n > i; i++){
		if(!comp.count(com[i])){
			comp[com[i]] = piv;
			piv++;
		}
	}
	for(long long i = 0; n > i; i++){
		long long p = search(comp[ar[i]] - 1) + 1;
		p = p % mod;
		//cout << p << "\n";
		upd(comp[ar[i]] , p);
	}
	cout << search(n) % mod;


}