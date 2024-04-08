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
const int nMax = 1000;
char layout[nMax][nMax];
long long vis[nMax][nMax];
long long n , m;
void dfs(long long x , long long y){
	vis[x][y] = 1;
	if(x > 0 && vis[x - 1][y] == 0 && layout[x - 1][y] == '.'){
		dfs(x - 1 , y);
	}
	if(y > 0 && vis[x][y - 1] == 0 && layout[x][y - 1] == '.'){
		dfs(x , y - 1);
	}
	if(n > (x + 1) && vis[x + 1][y] == 0 && layout[x + 1][y] == '.'){
		dfs(x + 1 , y);
	}
	if(m > (y + 1) && vis[x][y + 1] == 0 && layout[x][y + 1] == '.'){
		dfs(x , y + 1);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long cnt;
	char a;
	cin >> n >> m;
	for(long long i = 0; n > i; i++){
		for(long long j = 0; m > j; j++){
			cin >> a;
			layout[i][j] = a;
		}
	}
	cnt = 0;
	for(long long i = 0; n > i; i++){
		for(long long j = 0; m > j; j++){
			if(vis[i][j] == 0 && layout[i][j] == '.'){
				cnt++;
				dfs(i , j);
			}
		}
	}
	cout << cnt;

	
}