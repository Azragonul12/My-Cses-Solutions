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
	long long n , k;
	vector <long long> lis;
	cin >> n;
	for(long long i = 0; n > i; i++){
		cin >> k;
		auto up = upper_bound(lis.begin() , lis.end() , k);
		if(up == lis.end()){
			lis.push_back(k);
		}
		else{
			lis[up - lis.begin()] = k;
		}
	}
	cout << lis.size();
	
}