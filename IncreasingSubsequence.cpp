#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<numeric>
#include <cstring>
#include<utility>
#include<set>
#include<array>
#include<bitset>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n , p;
	cin >> n;
	vector <long long> lis;
	for(long long i = 0; n > i; i++){
		cin >> p;
		auto low = lower_bound(lis.begin(), lis.end() , p);
		if(low == lis.end()){
			lis.push_back(p);
		}
		else{
			*low = p;
			//lis[low - lis.begin()] = p;
		}
	}
	cout << lis.size();
	
}