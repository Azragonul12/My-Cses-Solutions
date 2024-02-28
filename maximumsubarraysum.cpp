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
	long long n , m , cnt , mxCnt;
    mxCnt = -(1e9 + 7);
    cnt = mxCnt;
    cin >> n;
    for(long long i = 0; n > i; i++){
        cin >> m;
        cnt = max(cnt + m , m);
        mxCnt = max(cnt , mxCnt);
    }
    cout << mxCnt;
	
}