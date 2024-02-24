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
	long long n , x , p , l , r , count , wCnt , numCnt;
	vector <long long> children;
	cin >> n >> x;
	l = 0;
	count = 1;
	numCnt = 0;
	wCnt = 0;
	r = (n-1);
	for(long long i = 0; n > i; i++){
		cin >> p;
		children.push_back(p);
	}
	sort(children.begin(), children.end());
	while(r >= l && l < n && r >= 0){
		//cout << wCnt << " ";
		if((wCnt + children[r]) <= x && numCnt < 2){
			wCnt += children[r];
			numCnt++;
			r--;
		}
		else{
			if((wCnt + children[l]) <= x && numCnt < 2){
				wCnt += children[l];
				numCnt++;
				l++;
			}
			else{
				wCnt = 0;
				count++;
				numCnt = 0;
			}
		}
	}
	if(wCnt == 0){
		count--;
	}
	cout << count;
	
}