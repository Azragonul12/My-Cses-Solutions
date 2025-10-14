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
struct Node{
	Node* left;
	Node* right;
	long long val;
	Node(){
		left = NULL;
		right = NULL;
		val = 0;
	}
 
	Node(Node* a){
		left = a -> left;
		right = a-> right;
		val = a -> val;
 
	}
};
vector <Node*> roots;
long long sys[nMax];
long long ar[nMax];
 
void build(long long l , long long r , Node* nod){
	if(l > r){
		return;
	}
	if(l == r){
		nod -> val = ar[l];
		return;
	}
	nod -> left = new Node();
	nod -> right = new Node();
	long long m = (l + r) / 2;
	build(l , m , nod -> left);
	build(m + 1 , r , nod -> right);
	nod -> val = (nod -> right -> val + nod -> left -> val);
}
 
void update(long long l , long long r , long long f , long long v , Node* nod){
	if(l > r || f > r || l > f){
		return;
	}
	if(l == r){
		nod -> val = v;
		return;
	}
	long long m = (l + r) / 2;
	if(l <= f && f <= m){
		nod -> left = new Node(nod -> left);
		update(l , m , f , v , nod -> left);
	}
	else{
		nod -> right = new Node(nod -> right);
		update(m + 1 , r , f , v , nod -> right);
	}
	nod -> val = (nod -> right -> val + nod -> left -> val);
}
 
long long search(long long l , long long r , long long fl , long long fr , Node* nod){
	if(l > r || fl > r || fr < l){
		return 0;
	}
	if(fl <= l && r <= fr){
		return nod -> val;
	}
	long long m = (l + r) / 2;
	return (search(l , m , fl , fr , nod -> left) + search(m + 1 , r, fl , fr , nod -> right));
 
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n , q , k , a , b , x , piv;
	cin >> n >> q;
	for(long long i = 1; n >= i; i++){
		cin >> ar[i];
	}
	Node* temp = new Node();
	build(1 , n , temp);
	roots.push_back(temp);
	sys[1] = 0;
	piv = 2;
	for(long long i = 0; q > i; i++){
		cin >> x;
		if(x == 1){
			cin >> k >> a >> b;
			temp = new Node(roots[sys[k]]);
			update(1 , n , a , b , temp);
			roots.push_back(temp);
			sys[k] = roots.size() - 1;
		}
		if(x == 2){
			cin >> k >> a >> b;
			cout << search(1 , n , a , b , roots[sys[k]]) << "\n";
		}
		if(x == 3){
			cin >> k;
			sys[piv] = sys[k];
			piv++;
		}
	}
	
}