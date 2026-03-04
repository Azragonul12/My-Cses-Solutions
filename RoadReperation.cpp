#include"bits/stdc++.h"
using namespace std;
const int nMax = 2e5 + 7;
vector <array <long long , 3> > edges;
long long par[nMax];

long long findPar(long long a){
	if(par[a] == a){
		return a;
	}
	return par[par[a]] = findPar(par[a]);
}
long long uni(long long a , long long b){
	if(findPar(a) == findPar(b)){
		return 0;
	}

	par[findPar(a)] = par[findPar(b)];
	return 1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	array <long long , 3> a;
	long long n , m , l , r , x;
	cin >> n >> m;
	for(long long i = 0; n >= i; i++){
		par[i] = i;
	}
	for(long long i = 0; m > i; i++){
		cin >> l >> r >> x;
		a[0] = x;
		a[1] = l;
		a[2] = r;
		edges.push_back(a);
	}
	sort(edges.begin(), edges.end());


	long long ans = 0;
	for(long long i = 0; m > i; i++){
		ans += uni(edges[i][1] , edges[i][2]) * edges[i][0];
	}
	x = 0;
	for(long long i = 1; n >= i; i++){
		if(par[i] == i){
			x++;
		}

	}

	if(x > 1){
		cout << "IMPOSSIBLE";
		return 0;
	}
	cout << ans;
}