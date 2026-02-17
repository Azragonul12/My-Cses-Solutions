#include"bits/stdc++.h"
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n , k , l , r;
	cin >> n >> k;
	long long cnt = 0 , cn = 0;
 
	vector <pair <long long , long long> > ar;
	for(long long i = 0; n > i; i++){
		cin >> l >> r;
		ar.push_back(make_pair(r , l));
 
	}
	sort(ar.begin(), ar.end());
	
 
	multiset <long long> unQue;
	for(long long i = 0; n > i; i++){
		//cout << ar[i].second << " " << ar[i].first;
		if(unQue.size()){
			auto up = unQue.upper_bound(ar[i].second);
			if(up != unQue.begin()){
				cnt++;
				up--;
				unQue.erase(up);
				unQue.insert(ar[i].first);
			}
			else{
				if(unQue.size() < k){
					cnt++;
					unQue.insert(ar[i].first);
				}
			}
		}
		else{
			cnt++;
 
			unQue.insert(ar[i].first);
			//cout << " aldım";
		}
		//cout << "\n";
	}
	cout << cnt;
 
 
}