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
const int nMax = 8;
long long hamle[nMax * nMax];
long long vis[nMax][nMax];
long long check(long long x , long long y){
	if(x >= 0 && 7 > x && y >= 0 && 7 > y && vis[x][y] == 0){
		return 1;
	}
	return 0;
}
long long dfs(long long x , long long y , long long ham){
	if(x == 6 && y == 0){
		//cout << ham << " ";
		if(ham >= 48){
			return 1;
		}
		else{
			return 0;
		}
	}
	//cout << x << " " << y << " " << ham << "..\n";
	//cout << vis[x - 1][y] << " " << vis[x + 1][y] << " " << vis[x][y - 1] << " " << vis[x][y + 1] << "\n";
	long long p = 0;
	if(!check(x + 1 , y) && !check(x - 1, y) && check(x , y - 1) && check(x , y + 1)){
		return 0;
	}
	if(check(x - 1, y) && check(x + 1, y) && !check(x , y + 1) && !check(x, y - 1)){
		return 0;
	}
	
	vis[x][y] = 1;
	if(hamle[ham] != 0){
		if(hamle[ham] == 1){
			if(check(x - 1 , y)){
				p += dfs(x - 1 , y , ham + 1);
			}
 
		}
		if(hamle[ham] == 2){
			if(check(x , y + 1)){
				p += dfs(x , y + 1, ham + 1);
			}
		}
		if(hamle[ham] == 3){
			if(check(x + 1 , y)){
				p += dfs(x + 1, y , ham + 1);
			}
 
		}
		if(hamle[ham] == 4){
			if(check(x, y - 1)){
				p += dfs(x , y - 1, ham + 1);
			}
		}
	}
	else{
 
		if(check(x - 1 , y)){
			p += dfs(x - 1 , y, ham + 1);
		}
		if(check(x + 1 , y)){
			p += dfs(x + 1 , y, ham + 1);
		}
		if(check(x , y - 1)){
			p += dfs(x , y - 1, ham + 1);
		}
		if(check(x , y + 1)){
			p += dfs(x , y + 1, ham + 1);
		}
 
	}
 
 
	vis[x][y] = 0;
	return p;
}
 
int main(){
	string str;
	cin >> str;
 
	for(long long i = 0; 48 > i; i++){
		if(str[i] == '?'){
			hamle[i] = 0;
		}
		if(str[i] == 'U'){
			hamle[i] = 1;
		}
		if(str[i] == 'D'){
			hamle[i] = 3;
		}
		if(str[i] == 'L'){
			hamle[i] = 4;
		}
		if(str[i] == 'R'){
			hamle[i] = 2;
		}
 
	}
	for(long long i = 0; 7 >= i; i++){
		for(long long j = 0; 7 >= j; j++){
			vis[i][j] = 0;
		}
	}
	cout <<dfs(0 , 0,  0);
 
	
}