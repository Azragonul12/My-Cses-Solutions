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
	long long tst;
	cin >> tst;
	while(tst--){
		long long n;
		long long h = 1 , l = 10;
		long long p = 9;
		cin >> n;
		while(n > (h * p)){
			n -= (h * p);
			h++;
			p *= 10;
		}
		p /= 9;
		p += ((n - 1) / h);
		for(long long i = 1; h - ((n - 1) % h) > i; i++){
			p /= 10;
		}
		
		cout << p % 10 << "\n";
 
 
	}
	
}