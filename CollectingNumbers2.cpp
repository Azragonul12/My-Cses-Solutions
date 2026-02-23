#include<bits/stdc++.h>
using namespace std;
const int nMax = (2 * (1e5)) + 7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n , x , cnt , m , y;
	long long place[nMax];
	long long normal[nMax];
	cin >> n >> m;
	cnt = 1;
	place[n + 1] = 1e9 + 7;
	place[0] = -1e9 + 7;
	for(long long i = 0; n > i; i++){
		cin >> x;
		normal[i] = x;
		place[x] = i;
	}
	for(long long i = 1; n > i; i++){
		if(place[i] > place[i + 1]){
			cnt++;
		}
	}
	for(long long i = 0; m > i; i++){
		cin >> x >> y;
		int tmp = normal[x - 1];
		normal[x - 1] = normal[y - 1];
		normal[y - 1] = tmp;
		tmp = x;
		x = normal[y - 1];
		y = normal[tmp - 1]; 
		int newx , newy;
		newx = place[y];
		newy = place[x];
		//cout << cnt << " " << x << " " << y << " ";
		if((place[x] < place[x - 1]) && (newx >= place[x - 1])){
			if(newx == place[x-1]){
				if(newx > newy){
					cnt--;
				}
			}
			else{
				cnt--;	
			}
		}
		if((place[x] > place[x - 1]) && (newx <= place[x - 1])){
			if(newx == place[x-1]){
				if(newx < newy){
					cnt++;
				}
			}
			else{
				cnt++;	
			}
		}
		if((place[y] < place[y - 1]) && (newy >= place[y - 1])){
			if(newy == place[y-1]){
				if(newy > newx){
					cnt--;
				}
			}
			else{
				cnt--;	
			}
		}
		if((place[y] > place[y - 1]) && (newy <= place[y - 1])){
			if(newy == place[y-1]){
				if(newx > newy){
					cnt++;
				}
			}
			else{
				cnt++;	
			}
		}
		if(place[x] > place[x + 1] && newx <= place[x + 1]){
			if(newx == place[x + 1]){
				if(newx > newy){
					cnt--;
				}
			}
			else{
				cnt--;	
			}
		}
		if(place[x] < place[x + 1] && newx >= place[x + 1]){
			if(newx == place[x + 1]){
				if(newx < newy){
					cnt++;
				}
			}
			else{
				cnt++;	
			}
		}
		if(place[y] > place[y + 1] && newy <= place[y + 1]){
			if(newy == place[y + 1]){
				if(newy > newx){
					cnt--;
				}
			}
			else{
				cnt--;	
			}
		}
		if(place[y] < place[y + 1] && newy >= place[y + 1]){
			if(newy == place[y + 1]){
				if(newx > newy){
					cnt++;
				}
			}
			else{
				cnt++;	
			}
		}
		cout << cnt << "\n";
		place[x] = newx;
		place[y] = newy;
	}


	
}
