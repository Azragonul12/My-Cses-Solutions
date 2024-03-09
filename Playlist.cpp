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
	long long n , k , l , r , mxSeq , piv;
	vector <long long> playlist;
	piv = 0;
	map <long long , long long> mp;
	cin >> n;
	l = 0;
	r = 0;
	for(long long i = 0; n > i; i++){
		cin >> k;
		playlist.push_back(k);
	}
	mxSeq = 0;
	while(r >= l && n > l && n > r){
		if(mp.count(playlist[r]) != 0){
			int tar = mp[playlist[r]];
			while(l != tar && n > l && r > l){
				piv--;
				mp.erase(playlist[l]);
				l++;
			}
			if(l == tar){
				l++;
				piv--;

			}
			mp[playlist[r]] = r;
			piv++;
			r++;
		}
		else{
			mp[playlist[r]] = r;
			piv++;
			r++;
		}
		mxSeq = max(mxSeq , piv);
	}
	cout << mxSeq;

	
}