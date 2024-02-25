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
	long long n , a , b , last , count;
	vector <array <long long , 2> > movies;
	array <long long , 2> r;
	cin >> n;
	for(long long i = 0; n > i; i++){
		cin >> a >> b;
		r[0] = b;
		r[1] = a;
		movies.push_back(r);
	}
	sort(movies.begin(), movies.end());
	last = -1;
	count = 0;
	for(long long i = 0; n > i; i++){
		if(last <= movies[i][1]){
			count++;
			last = movies[i][0];
		}
	}
	cout << count;


	
}