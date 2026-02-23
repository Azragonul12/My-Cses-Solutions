#include<bits/stdc++.h>
using namespace std;
long long ex[30];
long long an[30];
long long n;
set <string> st;
void gen(long long num , string sr , long long ar[30]){
	if(num >= n){
		st.insert(sr);
		return;
	}
	for(long long i = 0; 30 > i; i++){
		if(ex[i] > ar[i]){
			char c = (char)('a' + i);
			ar[i]++;
			gen(num + 1 , sr + c , ar);
			ar[i]--;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long x;
	string str;
	cin >> str;
	n = str.length();
	for(long long i = 0; 30 > i; i++){
		ex[i] = 0;
		an[i] = 0;
	}
	for(long long i = 0; str.length() > i; i++){
		ex[str[i] - 'a']++;
	}
	str = ' ';
	gen(0 , str , an);
	cout << st.size() << "\n";
	for(auto it : st){
		cout << it << "\n";
	}
}
