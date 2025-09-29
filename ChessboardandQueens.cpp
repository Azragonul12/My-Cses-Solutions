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
long long cnt = 0;
void place(long long num , long long av[8][8]){
	if(num >= 8){
		cnt++;
		return;
	}
	for(long long i = 0; 8 > i; i++){
		if(av[num][i] == 1){
			long long ava[8][8];
			for(long long k = 0; 8 > k; k++){
				for(long long j = 0; 8 > j; j++){
					ava[k][j] = av[k][j];
					if(j == i){
						ava[k][j] = -1;
					}
					if(abs(num - k) == abs(i - j)){
						ava[k][j] = -1;
					}
				}
			}
			place(num + 1 , ava);
 
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long ava[8][8];
	long long n;
	string str;
	for(long long i = 0; 8 > i; i++){
		cin >> str;
		for(long long j = 0; 8 > j; j++){
			if(str[j] == '*'){
				ava[i][j] = -1;
			}
			else{
				ava[i][j] = 1;
			}
		}
	}
	place(0 , ava);
	cout << cnt;
	
}