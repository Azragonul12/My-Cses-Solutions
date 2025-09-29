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
const int nMax = 1e3 + 7;
long long grid[nMax][nMax];
long long n;
long long check(long long x , long long y){
	if(x >= 0 && n > x && y >= 0 && n > y){
		return 1;
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	long long x, y;
	array <long long , 2> pl;
	queue < array <long long , 2> > que;
	pl[0] = 0;
	pl[1] = 0;
	que.push(pl);
	for(long long i = 0; n > i; i++){
		for(long long j = 0; n > j; j++){
			grid[i][j] = 1e9 + 7;
		}
	}
	grid[0][0] = 0;
	while(que.size()){
		pl = que.front();
		x = pl[0];
		y = pl[1];
		que.pop();
		if(check(x + 2, y - 1) && grid[x + 2][y - 1] > (grid[x][y] + 1)){
			pl[0] = x + 2;
			pl[1] = y - 1;
			que.push(pl);
			grid[x + 2][y - 1] = grid[x][y] + 1;
		}
		if(check(x + 2 , y + 1) && grid[x + 2][y + 1] > (grid[x][y] + 1)){
			pl[0] = x + 2;
			pl[1] = y + 1;
			que.push(pl);
			grid[x + 2][y + 1] = grid[x][y] + 1;
		}
		if(check(x + 1 , y + 2) && grid[x + 1][y + 2] > (grid[x][y] + 1)){
			pl[0] = x + 1;
			pl[1] = y + 2;
			que.push(pl);
			grid[x + 1][y + 2] = grid[x][y] + 1;
		}
		if(check(x + 1 , y - 2) && grid[x + 1][y - 2] > (grid[x][y] + 1)){
			pl[0] = x + 1;
			pl[1] = y - 2;
			que.push(pl);
			grid[x + 1][y - 2] = grid[x][y] + 1;
		}
		if(check(x - 2 , y - 1) && grid[x - 2][y - 1] > (grid[x][y] + 1)){
			pl[0] = x - 2;
			pl[1] = y - 1;
			que.push(pl);
			grid[x - 2][y - 1] = grid[x][y] + 1;
		}
		if(check(x - 2 , y + 1) && grid[x - 2][y + 1] > (grid[x][y] + 1)){
			pl[0] = x - 2;
			pl[1] = y + 1;
			que.push(pl);
			grid[x - 2][y + 1] = grid[x][y] + 1;
		}
		if(check(x - 1 , y + 2) && grid[x - 1][y + 2] > (grid[x][y] + 1)){
			pl[0] = x - 1;
			pl[1] = y + 2;
			que.push(pl);
			grid[x - 1][y + 2] = grid[x][y] + 1;
		}
		if(check(x - 1 , y - 2) && grid[x - 1][y - 2] > (grid[x][y] + 1)){
			pl[0] = x - 1;
			pl[1] = y - 2;
			que.push(pl);
			grid[x - 1][y - 2] = grid[x][y] + 1;
		}

	}
	for(long long i = 0; n > i; i++){
		for(long long j = 0; n > j; j++){
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
	
}