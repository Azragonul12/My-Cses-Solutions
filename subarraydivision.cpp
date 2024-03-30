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
	long long n , x , a , sum , cnt;
	map <long long , long long> mp;
	sum = 0;
	cnt = 0;
	cin >> n;
	x = n;
	mp[0]++;
	for(long long i = 0; n > i; i++){
		cin >> a;
		sum += a;
		long long val;
		if(sum >= 0){
			val = (sum % x);
		}
		else{
			val = (x - (abs(sum) % x));
			if(val == x){
				val = 0;
			}
		}
		if(mp.count(val) != 0){
			cnt += mp[val];
		}
		mp[val]++;
		//cout << cnt << " ";

	}
	cout << cnt;
	
}