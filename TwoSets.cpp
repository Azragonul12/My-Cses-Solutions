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
	long long n,curSum,aimSum,curNum;
	cin>>n;
	if((n * (n+1)) % 4 == 0){
		aimSum = (long long)((n * (n+1)) / 4);
		curSum = 0;
		vector <long long> first_ans;
		vector <long long> second_ans;
		curNum = n;
		while(curSum <= aimSum && curNum){
			if((curNum + curSum) <= aimSum){
				curSum += curNum;
				first_ans.push_back(curNum);
			}
			else{
				second_ans.push_back(curNum);
			}
			curNum--;
		}
		if(curSum != aimSum){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
			cout<<first_ans.size()<<"\n";
			for(auto it : first_ans){
				cout<<it<<" ";
			}
			cout<<"\n"<<second_ans.size()<<"\n";
			for(auto it : second_ans){
				cout<<it<<" ";
			}
			cout<<"\n";

		}

	}
	else{
		cout<<"NO\n";
	}
}