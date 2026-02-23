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
long long st = 0;
vector <long long> ans[2];
void hanoi(long long num , long long a , long long b , long long c){
	st++;
	if(num == 0){
		st--;
		return;
	}
	hanoi(num - 1 , a , c , b);
	ans[0].push_back(a);
	ans[1].push_back(b);
	hanoi(num - 1 , c , b, a);
 
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	hanoi(n , 1 , 3 , 2);
	cout << st << "\n";
	for(long long i = 0; st > i; i++){
		cout << ans[0][i] << " "<<ans[1][i]<<"\n";
	}
}