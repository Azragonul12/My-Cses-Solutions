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
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	   long long n , m , cnt;
    vector <long long> a;
    cnt = 0;
    cin >> n;
    for(long long i = 0; n > i; i++){
        cin >> m;
        a.push_back(m);
    }
    sort(a.begin() , a.end());
    for(long long i = 0; n > i; i++){
        cnt += abs(a[n / 2] - a[i]);
    }
    cout << cnt;
	
}