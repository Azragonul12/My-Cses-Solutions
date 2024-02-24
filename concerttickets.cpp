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
	
	long long n , m , h , t;
	multiset <long long> tickets;
	vector <long long> price;
	cin >> n >> m;
	for(long long i = 0; n > i; i++){
		cin >> h;
		tickets.insert(h);
	}
	for(long long i = 0; m > i; i++){
		cin >> t;
		price.push_back(t);
	}
	for(long long i = 0; m > i; i++){
		auto up = tickets.upper_bound(price[i]);
		if(up == tickets.begin()){
			cout << "-1 \n";
		}
		else{
			up--;
			cout << *up << "\n";
			tickets.erase(up);
		}
	}

}