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
#include<array>
#include<bitset>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long x , n , p;
	multiset <long long> passage;
	set <long long> lights;
	cin >> x >> n;
	passage.insert(x);
	lights.insert(x);
	lights.insert(0);
	for(long long i = 0; n > i; i++){
		cin >> p;
		auto up = lights.upper_bound(p);
		long long l , r;
		//cout << *up;
		r = *up;
		up--;
		l = *up;
		passage.erase(passage.find(abs(r - l)));
		passage.insert(abs(r - p));
		passage.insert(abs(p - l));
		lights.insert(p);
		
		auto ans = *(--passage.end());
		cout << ans << "\n";
		
	}
	
}