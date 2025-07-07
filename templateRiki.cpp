#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define all(v) v.begin(),v.end() 
#define rall(v) v.rbegin(),v.rend()

#define ii    pair<int,int> 

/*
#define typeOfData ii
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ordered_set tree<typeOfData, null_type,less<typeOfData>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace __gnu_pbds;
*/

#define LINE                    if(debug) { cerr << " ------------------------------------------ " << endl; }
#define debug1(A)           	if(debug) { cerr << "? " << #A << " : " << A << endl; }
#define debug2(A, B)            if(debug) { cerr << "? [ " << #A << " = " << A << " | " << #B << " = " << B << " ]" << endl; }
#define debug3(A, B, C)         if(debug) { cerr << "? [ " << #A << " = " << A << " | " << #B << " = " << B << " | " << #C << " = " << C << " ]" << endl; }
#define debugPair(a) 			if(debug) { cerr << "? " << #a << ": ( " << a.first << " , " << a.second << " )" << endl; }
#define debugList(A)            if(debug) { cerr << "? " << #A << ": "; if(debug) { bool leonelCheems = 0; cerr << "[ ";  for(auto x : A) { if(!leonelCheems) cerr << x , leonelCheems = 1; else cerr << " , " << x ;} cerr << " ]" << endl; } }
#define printList(A) 		    { bool leonelCheems = 0; for(auto x : A) { if(!leonelCheems) {cout << x; leonelCheems = 1;}else {cout << " " << x;}} cout << endl; }
#define debugIterablePairs(P) 	if(debug) {  cerr << "? " << #P << " : "; cerr << "{ " << endl; for(auto it : P) { cerr << "    " << it.first << " -> " << it.second << endl; } cerr << "} " << endl;  }
#define debugGraph(GP)          if(debug) { cerr << "? " << #GP << " = "; cerr << "{ " << endl; int cntNodes = 0; for(vi adj : GP) { if(adj.size()) { cerr << "   "; cerr << cntNodes << " => "; debugList(adj) } cntNodes ++;} cerr << "}" << endl;}
#define debugGraphWeight(GP) 	if(debug) { cerr << "? " << #GP << " = {" << endl; int cntNodes = 0; for(auto it : GP ){ if( it.size() ){ cerr << cntNodes << " => [ "; for(auto iter : it){ cerr << iter.first << "-w{" << iter.second << "} "; } cerr << "]" << endl; } cntNodes++; } }
#define debugMatrix(arr,F, C)   if(debug) { cerr << "? " << #arr << endl; for(int i = 0 ; i < F ; i++){ cerr << "[ "; for(int j = 0 ; j < C ; j++){ cerr << arr[i][j] << " "; } cerr << "]" << endl;} }
#define executeTime         	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#define FOR(i, l, r)        	for(int i = l; i < r ; i ++)
#define endl '\n';
#define sz(A) 					(int)A.size()

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int    N    = 1e5  + 9;
const int    mod  = 1e9  + 7;
const int    inf  = 2e9  + 9;
const ll     modL = 1e9  + 7;
const ll     infL = 2e18 + 9;
const double pi   = acos(-1);

void init();
bool debug = { 1 };

void PorLaCheemsia(int testCase) { 
  
} 
 
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	init();
	int t = 1;
	//cin >> t;
	FOR(i, 1, t + 1) PorLaCheemsia(i);
	return 0;
}

void init() {
	// freopen("ccski.in", "r", stdin);
	// freopen("ccski.out", "w", stdout);
}
