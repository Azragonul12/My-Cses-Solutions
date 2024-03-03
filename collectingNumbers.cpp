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
const int nMax = (2 * (1e5)) + 7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n , x , cnt;
	long long place[nMax];
	cin >> n;
	cnt = 1;
	for(long long i = 0; n > i; i++){
		cin >> x;

		place[x] = i;
	}
	for(long long i = 1; n > i; i++){
		if(place[i] > place[i + 1]){
			cnt++;
		}
	}
	cout << cnt;

	
}