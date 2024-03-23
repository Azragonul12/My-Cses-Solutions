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
	long long tst;
	tst = 1;
	cin >> tst;
	while(tst--){
		long long n , x , mex , b , piv;
		b = 0;
		map <long long , long long> mp;
		vector <long long> bob;
		cin >> n;
		for(long long i = 0; n > i; i++){
			cin >> x;
			mp[x]++;
		}
		piv = 0;
		b = 0;
		mex = -1;
		while((n + 1) >= piv){
			if(mp.count(piv) == 1 && mp[piv] == 1){
				bob.push_back(piv);
			}
			if(mex == - 1 && mp.count(piv) == 0){
				mex = piv;
			}

			piv++;
		}
		if(bob.size() < 2){
			cout << mex << "\n";
		}
		else{
			cout << min(bob[1] , mex) << "\n";
		}
		


		
	}
	
}