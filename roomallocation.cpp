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
const int nMax = (2 * 1e5) + 7;
bool comp(array <long long , 3> a , array <long long , 3> b){
	if(a[0] ^ b[0]){
		return a[0] < b[0];
		
	}
	return a[1] > b[1];
	
 
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long n , k , a , b , y;
	map <long long , long long> mp;
	set <long long> ava;
	vector < array <long long , 3 > > visit;
	long long ans[nMax];
	array <long long , 3> l;
	cin >> n;
	for(long long i = 0; n > i; i++){
		cin >> a >> b;
		l[0] = a;
		l[1] = 1;
		l[2] = i;
		visit.push_back(l);

		l[0] = b;
		l[1] = -1;
		l[2] = i;
		visit.push_back(l);
	}
	sort(visit.begin(), visit.end() , comp);
	y = 0;
	k = 0;
	for(long long i = 0; (n * 2) > i; i++){
		y += visit[i][1];
		k = max(k , y);
	}
	for(long long i = 1; k >= i; i++){
		ava.insert(i);
	}
	for(long long i = 0; (n * 2) > i; i++){
		if(visit[i][1] == 1){
			auto as = *ava.begin();
			ans[visit[i][2]] = as;
			mp[visit[i][2]] = as;
			ava.erase(ava.find(as));
		}
		else{
			ava.insert(mp[visit[i][2]]);
			mp.erase(visit[i][2]);
		}
	}
	cout << k << "\n";
	for(long long i = 0; n > i; i++){
		cout << ans[i] << " ";
	}
}