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
	long long n , k , x , cnt , dis;
	map <long long , long long> mp;
	vector <long long> values;
	cin >> n >> k;
	for(long long i = 0; n > i; i++){
		cin >> x;
		values.push_back(x);
	}
	long long l , r;
	l = 0;
	r = 0;
	dis = 0;
	cnt = 0;
	while(n > r && n > l){
		if(mp.count(values[r]) == 0 || mp[values[r]] == 0){
			dis++;
			while(dis > k){
				//cout << dis <<" "<<l << "\n";
				if(mp[values[l]] == 1){
					dis--;
				}
				mp[values[l]]--;
				l++;
			}
			cnt+= (r - l) + 1;
			mp[values[r]]++;
			r++;
		}
		else{
			cnt+= (r - l) + 1;
			mp[values[r]]++;
			r++;
		}
	}
	cout << cnt;
	
	
}