#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<numeric>
#include <cstring>
#include<utility>
#include<set>
#include<array>
#include<bitset>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n , m;
	cin >> n >> m;
	char grid[507][507];
	for(long long i = 0; n > i; i++){
		for(long long j = 0; m > j; j++){
			cin >> grid[i][j];
		}
	}
	for(long long i = 0; n > i; i++){
		for(long long j = 0; m > j; j++){
			if((i + j) % 2 == 0){
				if(grid[i][j] == 'A'){
					grid[i][j] = 'D';
				}
				else{
					grid[i][j] = 'A';
				}
			}
			else{
				if(grid[i][j] == 'C'){
					grid[i][j] = 'B';
				}
				else{
					grid[i][j] = 'C';
				}
 
			}
		}
	}
	for(long long i = 0; n > i; i++){
		for(long long j = 0; m > j; j++){
			cout << grid[i][j];
		}
		cout << "\n";
	}
 
	
}