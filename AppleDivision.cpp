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
long long n , mexs;
vector <long long> ap;
void sl(long long num , long long o , long long p){
	//cout << num << " " << o << " " << p << "\n";
	if(num > n){
		mexs = min(abs(o - p) , mexs);
		return;
	}
	sl(num + 1 , o + ap[num - 1] , p);
	sl(num + 1 , o , p + ap[num - 1]);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	mexs = 1e9 + 17;
	cin >> n;
	long long x;
	for(long long i = 0; n > i; i++){
		cin >> x;
		ap.push_back(x);
	}
	sl(1 , 0 , 0);
	cout << mexs;
	
}