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
	long long n , x , a;
	vector <array <long long , 2> > nums;
	array <long long , 2> ar;
	cin >> n >> x;
	for(long long i = 0; n > i; i++){
		cin >> a;
		ar[0] = a;
		ar[1] = i + 1;
		nums.push_back(ar);
	}
	sort(nums.begin(), nums.end());
	for(long long i = 0; n > i; i++){
		long long l , r , fs;
		l= 0;
		r = n - 1;
		fs = (x - nums[i][0]);
		while(l < n && r >= 0){
			if(l == i){
				l++;
			}
			if(r == i){
				r--;
			}
			if(nums[l][0] + nums[r][0] < fs){
				l++;
			}
			else{
				if(nums[l][0] + nums[r][0] > fs){
					r--;
				}
				else{
					if(l == r){
						break;
					}
					cout << nums[r][1] << " " << nums[l][1] << " " << nums[i][1] << "\n";
					return 0;
				}
			}
		}

	}
	cout << "IMPOSSIBLE";
	
}