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
	cin >> n >> x;
	mp[0]++;
	for(long long i = 0; n > i; i++){
		cin >> a;
		sum += a;
		if(mp.count(sum - x) != 0){
			cnt += mp[sum - x];
		}
		mp[sum]++;

	}
	cout << cnt;
	
}