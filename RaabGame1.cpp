#include<bits/stdc++.h>
using namespace std;
int main(){
 
	long long tst;
	cin >> tst;
	while(tst--){
		long long a , b , n;
		cin >> n >> b >> a;
 
		if(a + b > n ||(a * b == 0 && (a + b) != 0)){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
			for(long long i = 0; n > i; i++){
				cout << i + 1 << " ";
			}
			cout << "\n";
			for(long long i = 0; (n - (a + b)) > i; i++){
				cout << i + 1 << " ";
			}
			long long p = (n - a) + 1;
			for(long long i = 0; a > i; i++){
				cout << p << " ";
				p++;
			}
			p = (n - (a + b)) + 1;
			for(long long i = 0; b > i; i++){
				cout << p << " ";
				p++;
			}
			cout << "\n";
 
 
		}
	}
}