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
	long long n , x , ans1 , ans2 , flag , a , l ,r;
	vector <pair <long long , long long> > nums;
	flag = 0;
	cin >> n >> x;
	for(long long i = 0; n > i; i++){
		cin >> a;
		nums.push_back(make_pair(a , i));
	}
	l = 0;
	r = (n - 1);
	sort(nums.begin(), nums.end());
	while(r > l && n > l && r >= 0 && flag == 0){
		if((nums[l].first + nums[r].first) > x){
			r--;
		}
		else{
			if((nums[l].first + nums[r].first) < x){
				l++;
			}
			else if((nums[l].first + nums[r].first) == x){
				ans1 = (nums[l].second);
				ans2 = (nums[r].second);
				flag = 1;
			}
		}
	}
	if(flag == 1){
		cout << ans1 + 1 << " " << ans2 + 1;
	}
	else{
		cout << "IMPOSSIBLE";
	}

	
}