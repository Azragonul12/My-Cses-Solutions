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
#include<bitset>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n , m , k , l , l1 , a , cnt;
	vector <long long> apartments;
	vector <long long> applicants;
	cin >> n >> m >> k;
	cnt = 0;
	for(long long i = 0; n > i; i++){
		cin >> a;
		applicants.push_back(a);
	}
	for(long long i = 0; m > i; i++){
		cin >> a;
		apartments.push_back(a);
	}
	sort(applicants.begin() , applicants.end());
	sort(apartments.begin() , apartments.end());
	l = 0;
	l1 = 0;
	while(l1 < m && l < n){
		if((applicants[l] >= (apartments[l1] - k)) && (applicants[l] <= (apartments[l1] + k))){
			cnt++;
			l1++;
			l++;
		}
		else{
			if((applicants[l] < (apartments[l1] - k))){
				l++;
			}
			else{
				l1++;
			}

		}
	}
	cout << cnt;

	
}