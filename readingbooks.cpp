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
	long long n , t , cnt , mxT;
	cin >> n;
	mxT = 0;
	cnt = 0;
	for(long long i = 0; n > i; i++){
		cin >> t;
		cnt += t;
		mxT = max(mxT , t);

	}
	cout << max(mxT * 2 , cnt) ;
	
}