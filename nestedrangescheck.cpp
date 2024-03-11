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
const int nMax = (16 * 1e5) + 7;
const int mMax = (2 * 1e5) + 7;
long long rSeg[nMax];
long long lSeg[nMax];
bool comp(array <long long , 3> a , array <long long , 3> b){
	if(a[0] ^ b[0]){
		return a[0] < b[0];
		
	}
	return a[1] > b[1];
	
 
}
void updater(long long l , long long r , long long num , long long target){
	if(l > r){
		return;
	}
	if(l > target || target > r){
		return;
	}
	if(l == r){
		rSeg[num] += 1;
		return;
	}
	long long m = (r + l);
	m /= 2;
	updater(l , m , num * 2 , target);
	updater(m + 1 , r , (num * 2) + 1 , target);
	rSeg[num] = rSeg[num * 2] + rSeg[(num * 2) + 1];
}
long long searchr(long long l , long long r ,long long fl , long long fr , long long num){
	if(l > r){
		return 0;
	}
	if(l < fl && fr < r){
		return 0;
	}
	if(r < fl || fr < l){
		return 0;
	}
	if(fl <= l && r <= fr){
		return rSeg[num];
	}
	if(l == r){
		return 0;
	}
	long long m = (r + l);
	m /= 2;
	return (searchr(l , m ,fl , fr, num * 2) + searchr(m + 1 , r , fl , fr, (num * 2) + 1));

}
void updatel(long long l , long long r , long long num , long long target){
	if(l > r){
		return;
	}
	if(l > target || target > r){
		return;
	}
	if(l == r){
		lSeg[num] += 1;
		return;
	}
	long long m = (r + l);
	m /= 2;
	updatel(l , m , num * 2 , target);
	updatel(m + 1 , r , (num * 2) + 1 , target);
	lSeg[num] = lSeg[num * 2] + lSeg[(num * 2) + 1];
}
long long searchl(long long l , long long r ,long long fl , long long fr , long long num){
	if(l > r){
		return 0;
	}
	if(l < fl && fr < r){
		return 0;
	}
	if(r < fl || fr < l){
		return 0;
	}
	if(fl <= l && r <= fr){
	//	cout << fl << " "<< fr << " " << lSeg[num] <<"\n";
		return lSeg[num];
	}
	if(l == r){
		return 0;
	}
	long long m = (r + l);
	m /= 2;
	return (searchl(l , m ,fl , fr, num * 2) + searchl(m + 1 , r , fl , fr, (num * 2) + 1));

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n , x , y , cmp;
	vector <array <long long , 3> > ranges;
	vector <long long> compress;
	unordered_map <long long , long long> mp;
	array <long long , 3> a;
	long long ans[mMax][2];
	cin >> n;
	cmp = 1;
	for(long long i = 0; n > i; i++){
		cin >> x >> y;
		a[0] = x;
		a[1] = y;
		a[2] = i + 1;
		compress.push_back(x);
		compress.push_back(y);
		ranges.push_back(a);
	}
	sort(compress.begin(), compress.end());
	for(long long i = 0; 2 * n > i; i++){
		if(mp.count(compress[i]) == 0){
			mp[compress[i]] = cmp;
			cmp++;
		}
	}
	for(long long i = 0; n > i; i++){
		ranges[i][0] = mp[ranges[i][0]];
		ranges[i][1] = mp[ranges[i][1]];
	}
	sort(ranges.begin(), ranges.end() , comp);
	for(long long i = 0; n > i; i++){
		ans[ranges[i][2]][1] = searchl(1 , cmp , ranges[i][1] , cmp , 1);
		updatel(1 , cmp , 1 , ranges[i][1]);
	}
	for(long long i = (n - 1); 0 <= i; i--){
		ans[ranges[i][2]][0] = searchr(1 , cmp , 1, ranges[i][1] , 1);
		updater(1 , cmp , 1 , ranges[i][1]);
	}
	for(long long i = 1; n >= i; i++){
		if(ans[i][0]){
			cout << "1 ";
		}
		else{
			cout << "0 ";
		}
	}
	cout << "\n";
	for(long long i = 1; n >= i; i++){
		if(ans[i][1]){
			cout << "1 ";
		}
		else{
			cout << "0 ";
		}
	}




	
}