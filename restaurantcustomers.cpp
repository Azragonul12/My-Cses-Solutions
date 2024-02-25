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
	long long n , a , l , count , maxCount;
	count = 0;
	maxCount = 0;
	vector <array <long long , 2> > customers;
	array <long long , 2> r;
	cin >> n;
	for(long long i = 0; n > i; i++){
		cin >> a >> l;
		r[0] = a;
		r[1] = 1;
		customers.push_back(r);

		r[0] = l;
		r[1] = -1;
		customers.push_back(r);
	}
	sort(customers.begin(), customers.end());
	for(long long i = 0; (2 * n) > i; i++){
		count += customers[i][1];
		maxCount = max(maxCount , count);
	}
	cout << maxCount;

	
}