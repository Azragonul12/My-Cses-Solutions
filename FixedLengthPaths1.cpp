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
 
const int nMax = 2e5 + 7;
long long n , k , cnt = 0;
map <long long , long long> mp[nMax];
vector <long long> adj[nMax];
long long dep[nMax];
void dfs(long long num , long long par){
 
    for(long long i = 0; adj[num].size() > i; i++){
        if(adj[num][i] != par){
            dep[adj[num][i]] = dep[num] + 1;
            dfs(adj[num][i] , num);
        }
    }
}
void df(long long num , long long par){
    if(adj[num].size() <= 1 && par != -1){
        return;
    }
    long long h = -1;
    for(long long i = 0; adj[num].size() > i; i++){
        if(adj[num][i] != par){
            df(adj[num][i] , num);
            if(h == -1){
                h = i;
            }
            else{
                if(mp[adj[num][h]].size() < mp[adj[num][i]].size()){
                    h = i;
                }
            }
        }
    }
    //cout << h << " ";
    swap(mp[num] , mp[adj[num][h]]);
    for(long long i = 0; adj[num].size() > i; i++){
        if(adj[num][i] != par){
            for(auto uv : mp[adj[num][i]]){
                cnt += mp[num][k - uv.first + (2 * dep[num])] * uv.second;
            }
            for(auto uv : mp[adj[num][i]]){
                mp[num][uv.first] += uv.second;
            }
        }
 
 
           // cout << cnt << " " << num << "\n";    
    }
 
 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    long long l , r;
    for(long long i = 0; (n - 1) > i; i++){
        cin >> l >> r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    dfs(1 , -1);
    for(long long i = 1; n >= i; i++){
        mp[i][dep[i]]++;
    }
    df(1 , -1);
    cout <<  cnt;
 
}