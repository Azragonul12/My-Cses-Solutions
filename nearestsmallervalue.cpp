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
	long long n , x;
	stack <array <long long , 2> > st;
	array <long long , 2> a;
	cin >> n;
	a[0] = -1;
	a[1] = 0;
	st.push(a);
	for(long long i = 0; n > i; i++){
		cin >> x;
		while(st.size() && st.top()[0] >= x){
			st.pop();
		}
		cout << st.top()[1] << " ";
		a[0] = x;
		a[1] = i + 1;
		st.push(a);

	}
	
}