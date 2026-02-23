#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long Fastpow(long long Num, long long Pow){
	if(Pow == 0){
		return 1;
	}
	if(Pow % 2 == 1){
		return (Num * (Fastpow(Num , Pow/2) % mod) * (Fastpow(Num, Pow/2) % mod)) % mod;
	}
	else{
		return ((Fastpow(Num , Pow/2) % mod) * (Fastpow(Num, Pow/2) % mod)) % mod;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin>>n;
	cout<<Fastpow(2,n) % mod;
}
