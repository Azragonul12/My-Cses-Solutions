#include"bits/stdc++.h"
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n , a , b , x , s;
	cin >> n >> a >> b;
	vector <long long> ar;
	s = 0;
	ar.push_back(0);
	for(long long i = 0; n > i; i++){
		cin >> x;
		s += x;
		ar.push_back(s);
 
	}
	priority_queue <pair <long long , long long> > pq;
	vector <long long> ans;
	for(long long i = n; 0 <= i; i--){
 
		if((i + a - 1) <= n){
			pq.push(make_pair(ar[i + a - 1] , i + a - 1));
		}
		while(pq.size() && pq.top().second > (i + b - 1)){
			pq.pop();
		}
		if(pq.size()){
			ans.push_back(pq.top().first);
		}
		else{
			ans.push_back(-1);
		}
		
	}
	reverse(ans.begin(), ans.end());
	long long cnt = -(1e18);
	for(long long i = 1; n >= i; i++){
		//cout << ans[i] << " ";
		if(ans[i] != -1)
			cnt = max(cnt , ans[i] - ar[i - 1]);
	}
	cout << cnt;
 
	
 
	
}