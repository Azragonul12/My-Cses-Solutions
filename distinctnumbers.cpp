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
	long long n , a , cnt;
	map <long long , long long> mp;
	cin >> n;
	cnt = 0;
	for(long long i = 0; n > i; i++){
		cin >> a;
		mp[a]++;
		if(mp[a] == 1){
			cnt++;
		}
	}
	cout << cnt;
	
}