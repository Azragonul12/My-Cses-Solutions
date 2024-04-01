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
	long long n , k , x , l , r;
	vector <long long> arr;
	cin >> n >> k;
	r = 0;
	l = 0;
	for(long long i = 0; n > i; i++){
		cin >> x;
		r += x;
		arr.push_back(x);
	}
	while(r > l){
		long long m = ( l + r );
		m /= 2;
		long long cnt , sum;
		cnt = 1;
		sum = 0;
		for(long long i = 0; n > i; i++){
			if(sum + arr[i] > m){
				cnt++;
				sum = arr[i];
			}
			else{
				sum += arr[i];
			}
			if(arr[i] > m){
				cnt = (n + 1);
			}
		}
		if(cnt <= k){
			r = m;
		}
		else{
			l = (m + 1);
		}
	}
	cout << l;
	
}