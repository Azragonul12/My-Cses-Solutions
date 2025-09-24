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
const int nMax = 3e3 + 7;
long long n;
long long grid[nMax][nMax];
long long vis[nMax][nMax];
long long par[nMax][nMax];
long long cp(long long x , long long y){
	return (x * n) + y;
}
array <long long , 2> decomp(long long x){
	array <long long , 2> ar;
	ar[0] = x / n;
	ar[1] = (x % n);
	return ar;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long m , x , y;
	char c;
	cin >> n;
	for(long long i = 0; n > i; i++){
		for(long long j = 0; n > j; j++){
			cin >> c;
			grid[i][j] = c - 'A';
		}
	}
	string str;
	array < long long , 4 > a;
	array < long long , 2 > b;
	vector < array <long long , 4 > > ls;
	b[0] = 0;
	b[1] = 0;
	queue <array <long long , 2> > que;
 
	que.push(b);
	while(que.size()){
		x = que.front()[0];
		y = que.front()[1];
		//cout << x << " " << y << "\n";
		que.pop();
			vis[x][y] = 1;
			if((x + 1) < n && vis[x + 1][y] == 0){
				if((y + 1) < n && vis[x][y + 1] == 0){
					if(grid[x + 1][y] > grid[x][y + 1]){
						a[0] = grid[x][y + 1];
						a[1] = x;
						a[2] = y + 1;
						a[3] = cp(x , y);
						if(vis[a[1]][a[2]] == 0)
							ls.push_back(a);
						vis[a[1]][a[2]] = 1;
					}
					else{
						if(grid[x + 1][y] < grid[x][y + 1]){
							a[0] = grid[x + 1][y];
							a[1] = x + 1;
							a[2] = y;
							a[3] = cp(x , y);
							if(vis[a[1]][a[2]] == 0)
								ls.push_back(a);
							vis[a[1]][a[2]] = 1;
						}
						else{
							a[0] = grid[x + 1][y];
							a[1] = x + 1;
							a[2] = y;
							a[3] = cp(x , y);
							if(vis[a[1]][a[2]] == 0)
								ls.push_back(a);
							vis[a[1]][a[2]] = 1;
							a[0] = grid[x][y + 1];
							a[1] = x;
							a[2] = y + 1;
							a[3] = cp(x , y);
							if(vis[a[1]][a[2]] == 0)
								ls.push_back(a);
							vis[a[1]][a[2]] = 1;
 
						}
 
					}
				}
				else{
					a[0] = grid[x + 1][y];
					a[1] = x + 1;
					a[2] = y;
					a[3] = cp(x , y);
					if(vis[a[1]][a[2]] == 0)
						ls.push_back(a);
					vis[a[1]][a[2]] = 1;
				}
			}
			else{
				if((y + 1) < n && vis[x][y + 1] == 0){
					a[0] = grid[x][y + 1];
					a[1] = x;
					a[2] = y + 1;
					a[3] = cp(x , y);
					if(vis[a[1]][a[2]] == 0)
						ls.push_back(a);
					vis[a[1]][a[2]] = 1;
				}
 
			}
 
 
		if(que.size() == 0){
			sort(ls.begin() , ls.end());
			for(long long i = 0; ls.size() > i; i++){
				if(ls[i][0] == ls[0][0]){
					par[ls[i][1]][ls[i][2]] = ls[i][3];
					//cout << par[ls[i][1]][ls[i][2]] << " "  << ls[i][1] << " " <<ls[i][2] << "\n";
					b[0] = ls[i][1];
					b[1] = ls[i][2];
						que.push(b);
				}
			}
			ls.clear();
		}
	}
	b[0] = n - 1;
	b[1] = n - 1;
	while(b[0] != 0 || b[1] != 0){
		//cout << b[0] << " " << b[1]<<"\n";
		c = ('A' + grid[b[0]][b[1]]);
		str = str + c;
		b = decomp(par[b[0]][b[1]]);
	}
	c = ('A' + grid[0][0]);
	str = str + c;
	reverse(str.begin() , str.end());
	cout << str;
 
	
}