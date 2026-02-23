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
	long long tst, first ,second;
	cin>>tst;
	while(tst--){
		cin>>first>>second;
		if((first + second) % 3 == 0 && ((first + 1) / 2 <= second) && second <= (first * 2)){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
	
 
}
