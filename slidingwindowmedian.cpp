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
	multiset <long long> left;
	multiset <long long> right;
	long long n , k , x , med , rs , ls;
	vector <long long> arr;
	cin >> n >> k;
	rs = 0;
	ls = 0;
	for(long long i = 0; n > i; i++){
		cin >> x;
		arr.push_back(x);
	}
	med = arr[0];
	for(long long i = 1; k > i; i++){
		if(arr[i] > med){
			left.insert(arr[i]);
			ls++;
		}
		else{
			right.insert(arr[i]);
			rs++;
		}
		//cout << ls - rs << " ";
		if((ls - rs) > 1){
			right.insert(med);
			rs++;
			ls--;
			med = *left.begin();
			left.erase(left.find(med));
		}
		else{
			if((rs - ls) > 1){
				left.insert(med);
				ls++;
				rs--;
				med = *(--right.end());
				right.erase(right.find(med));
			}
		}
		if(rs > ls){
			left.insert(med);
			ls++;
			rs--;
			med = *(--right.end());
			right.erase(right.find(med));
		}

	}
	cout << med << " ";
	
	for(long long i = k; n > i; i++){
		if(arr[i] > med){
			ls++;
			left.insert(arr[i]);
		}
		else{
			rs++;
			right.insert(arr[i]);
		}
		//cout << (left.size()) - (right.size()) << " "<<piv<<" ";
		if((ls - rs) > 1){
			right.insert(med);
			rs++;
			ls--;
			med = *left.begin();
			left.erase(left.find(med));
		}
		else{
			if((rs - ls) > 1){
				left.insert(med);
				ls++;
				rs--;
				med = *(--right.end());
				right.erase(right.find(med));
			}
		}
		//cout << *left.begin() <<" " << *(--right.end())<< "\n";
		
		if(rs > ls){
			left.insert(med);
			ls++;
			rs--;
			med = *(--right.end());
			right.erase(right.find(med));
		}
		if(left.find(arr[i - k]) != left.end()){
			ls--;
			left.erase(left.find(arr[i - k]));
		}
		else{
			if(right.find(arr[i - k]) != right.end()){	
				rs--;
				right.erase(right.find(arr[i - k]));

			}
			else{
				med = *left.begin();
				ls--;
				left.erase(left.find(med));
			}

		}
	//	cout << ls << " "<< rs << " ";
		if((ls - rs) > 1){
			right.insert(med);
			rs++;
			ls--;
			med = *left.begin();
			left.erase(left.find(med));
		}
		else{
			if((rs - ls) > 1){
				left.insert(med);
				ls++;
				rs--;
				med = *(--right.end());
				right.erase(right.find(med));
			}
		}
		if(rs > ls){
			left.insert(med);
			ls++;
			rs--;
			med = *(--right.end());
			right.erase(right.find(med));
		}
		cout << med <<" ";

	}
	
	
}