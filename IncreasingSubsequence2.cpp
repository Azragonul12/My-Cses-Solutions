#include "bits/stdc++.h"
using namespace std;
const int nMax = 2e5 + 7;
const int mod = 1e9 + 7;
long long fenwick[nMax];
long long fenwick1[nMax];
long long n;
void upd(long long num , long long val){
	for(long long i = num; n >= i; i += (i & -i)){
		fenwick[i] += val;
	}
}
long long search(long long num){
	long long ans = 0;
	for(long long i = num; 0 < i; i -= (i & -i)){
		ans += fenwick[i];
	}
	return ans;
}

void upd1(long long num){
	for(long long i = num; n >= i; i += (i & -i)){
		fenwick1[i]++;
	}
}
long long search1(long long num){
	long long ans = 0;
	for(long long i = num; 0 < i; i -= (i & -i)){
		ans += fenwick1[i];
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long m , x;
	cin >> n;
	vector <long long> ar;
	vector <long long> com;
	unordered_map <long long> comp;
	for(long long i = 0; n > i; i++){
		cin >> x;
		ar.push_back(x);
		com.push_back(x);
	}
	sort(com.begin(), com.end());
	long long piv = 1;
	for(long long i = 0; n > i; i++){
		if(!comp.count(com[i])){
			comp[com[i]] = piv;
			piv++;
		}
	}
	for(long long i = 0; n > i; i++){
		upd1(comp[ar[i]]);

		upd(comp[ar[i]] , search(comp[ar[i]]) + search1(comp[ar[i]]));
	}
	cout << search(n);


}