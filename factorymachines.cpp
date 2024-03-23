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
	
	long long n , t , k , r , l , cnt;
	vector <long long> mach;
	cin >> n >> t;
	for(long long i = 0; n > i; i++){
		cin >> k;
		mach.push_back(k);
	}
	sort(mach.begin(), mach.end());
	l = 0;
	r = (mach[0] * t);
	while(r > l){
		cnt = 0;
		long long m = (( l + r ) / 2);
		for(long long i = 0; n > i; i++){
			cnt += (m / mach[i]);
		}
		if(cnt >= t){
			r = m;
		}
		else{
			l = m + 1;
		}

	}
	cout << r;
}