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
	
	long long n , f , d , cnt , time;
	vector <array <long long , 2> > tasks;
	array <long long , 2> a;
	cin >> n;
	cnt = 0;
	for(long long i = 0; n > i; i++){
		cin >> f >> d;
		a[0] = f;
		a[1] = d;
		tasks.push_back(a);
	}
	sort(tasks.begin(), tasks.end());
	time = 0;
	for(long long i = 0; n > i; i++){
		time += tasks[i][0];
		cnt += (tasks[i][1] - time);
	}
	cout << cnt;

	
}