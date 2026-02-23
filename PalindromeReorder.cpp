#include<bits/stdc++.h>
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
	string str;
	int dist=0;
	char mid;
	int numChar[30];
	vector <char> Ans;
	cin>>str;
	memset(numChar,0,sizeof(numChar));
	for(int i = 0; str.length()> i; i++){
		numChar[str[i] - 'A']++;
	}
	for(int i = 0; 30 > i; i++){
		if(numChar[i] % 2 == 1){
			dist++;
		}
	}
	if(dist > (str.length() % 2)){
		cout<<"NO SOLUTION";
	}
	else{
		for(int i = 0; 30 > i; i++){
			if(numChar[i] % 2 == 0){
				for(int j=0; numChar[i] / 2 > j; j++){
					Ans.push_back('A' + i);
				}
			}
			else{
				for(int j=0; numChar[i] / 2 > j; j++){
					Ans.push_back('A' + i);
				}
				mid = ('A' + i);
			}
		}
		for(int i = 0; Ans.size()>i ; i++){
			cout<<Ans[i];
		}
 
		
		if(str.length() % 2 == 1)	cout<<mid;
 
 
		for(int i = Ans.size() - 1; 0 <= i ; i--){
			cout<<Ans[i];
		}
	}
	
 
}