#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

//Debug
#define qwer 					cerr << "----------------------" << endl;
#define debugList(A)          	if(debug) { cerr << "? " << #A << ": "; if(debug) { bool band = 0; cerr << "[ ";  for(auto x : A) { if(!band) cerr << x , band = 1; else cerr << " , " << x ;} cerr << " ]" << endl; } }
#define debugVar(A)           	if(debug) { cerr << "? " << #A << " : " << A << endl; }
#define debugPair(a,b)          if(debug) { cerr << "?? " << #a << " : " << a << " | " << #b << " : " << b << endl; }
#define debugIterablePairs(P) 	if(debug) { qwer cerr << "? " << #P << " : "; cerr << "{ " << endl; for(auto it : P) { cerr << "    " << it.first << " -> " << it.second << endl; } cerr << "} " << endl; qwer }
#define debugGraph(GP)          if(debug) { cerr << "? " << #GP << " = "; cerr << "{ " << endl; int cntNodes = 0; for(vi adj : GP) { if(adj.size()) { cerr << "   "; cerr << cntNodes << " => "; debugList(adj) } cntNodes ++;} cerr << "}" << endl;}
#define debugGraphWeight(GP) 	if(debug) { qwer cerr << "? " << #GP << " = {" << endl; int cntNodes = 0; for(auto it : GP ){ if( it.size() ){ cerr << cntNodes << " => [ "; for(auto iter : it){ cerr << iter.fi << "-w{" << iter.se << "} "; } cerr << "]" << endl; } cntNodes++; } qwer }
#define debug1(a)	 			if(debug) { qwer cerr << "1? " << (a) << nl; qwer }
#define debug2(a,b) 			if(debug) { qwer cerr << "2? " << (a) << " " << (b) << nl; qwer }
#define debug3(a,b,c) 			if(debug) { qwer cerr << "3? " << (a) << " " << (b) << " " << (c) << nl; qwer }
#define debug4(a,b,c,d) 		if(debug) { qwer cerr << "4? " << (a) << " " << (b) << " " << (c) << " " << (d) << nl; qwer }

#define nl      '\n'
#define pb      push_back
#define all(v)  v.begin(),v.end() // inicio - fin
#define rall(v) v.rbegin(),v.rend() // fin - inicio

// CodeForces Optional
#define YES             cout << "YES" << nl;
#define NO              cout << "NO"  << nl;
#define YESNO(x)        cout << ((x)? "YES" : "NO") << nl;
#define fix(x)          cout << fixed << setprecision(x);
#define imp(x)          cout << (x) << nl;

#define executeTime     cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#define printList(A)    bool band = 0; for(auto x : A) { if(!band) {cout << x; band = 1;}else {cout << " " << x;}} cout << endl;
#define FOR(i,a,b)      for(int i=a ; i<b ; i++)
#define EACH(i,v)       for(auto &i : v)
#define REV(i,b,a)      for(int i=b ; i>=a ; i--)

#define mem(v,x)        memset(v, (x), sizeof(v))
#define sz(a)           (int) a.size()
#define make_unique(x)  (x).resize(unique(all((x))) - (x).begin())

#define ii pair<int,int> // 2
#define iii pair<ii,int> // 3
#define iiii pair<ii,ii> // 4

#define vi      vector<int>         // int
#define vpii    vector<ii>          // <int,int>
#define vs      vector<string>      // string
#define vll     vector<ll>          // long long
#define vpll    vector<<pair<ll,ll>> // <long,long>
#define vb     vector<bool>        // bool

// knight moves...
// int dx[] = {-1,-2,-2,-1,1,2,2,1};
// int dy[] = {-2,-1,1,2,2,1,-1,-2};

// grid moves without diagonal
// int dx[] = {0,-1,0,1};
// int dy[] = {-1,0,1,0};
 
// only all diagonal moves
int dx[] = {-1,-1,1,1};
int dy[] = {-1,1,1,-1};
 
// grid moves with diagonal
// int dx[] = {0,-1,-1,-1,0,1,1,1};
// int dy[] = {-1,-1,0,1,1,1,0,-1};

// Const
const int    N    = 2e5  + 9;
const int    mod  = 1e9  + 7;
const int    inf  = 2e9  + 9;
const ll     modL = 1e9  + 7;
const ll     infL = 2e18 + 9;
// Geometry
const double pi   = acos(-1);
const double EPS  = 1e-9;

bool debug = { 1 };
void init();

bool ok(int cx, int cy, int n, int m){
    return cx >=0 && cy >= 0 && cx < n && cy < m;
}

vector<vector<int>> med(N, vector<int> (N));
vector<vector<bool>> visited;

void bfs(ii i, vector<string> &grid, int n, int m){
    visited[i.first][i.second] = true;
    queue<iii> q;
    q.push({i,med[i.first][i.second]});
    if( med[i.first][i.second] == 0 ) {
        cout << "NO" << endl;
        return;
    }
    //options
    // int dis = 1;
    // vector<vector<int>> dis(n, vector<int> (m));
    // dis[i.first][i.second] = 1;
    while(!q.empty()){
        int cx = q.front().first.first, cy = q.front().first.second;
        int en = q.front().second;
        q.pop();
        if( grid[cx][cy] == 'T' ) {
            cout << "YES" << endl;
            return;
        }
        FOR(i,0,4){
            int xx = cx + dx[i];
            int yy = cy + dy[i];
            // cout << cx << " " <<  cy << nl;
            if( !ok(xx,yy,n,m) ) continue;
            if( grid[xx][yy] == '.' && !visited[xx][yy] && en >= 1){
                visited[xx][yy] = true;
                // dis++;
                // dis[xx][xx] = dis[cx][cy] + 1;
                if( med[xx][yy] > en - 1 ){
                    en = med[xx][yy];
                    med[xx][yy] = 0;
                    FOR(i,0,n) FOR(j,0,m) visited[i][j] = 0;
                }
                q.push({{xx,yy}, en - 1});
            }
        }
        
    }

}

void solve(int ith){ /*Mood Sociedad estancia*/
    int h,w;
    cin >> h >> w;
    vector<string> grid(h);
    for(string i : grid){
        cin >> i;
    }
    ii s = {-1,-1};
    FOR(i,0,h){
        FOR(j,0,w){
            if( grid[i][j] == 'S' ){
                s = {i,j};
                break;
            }
        }
    }
    int n; cin >> n;
    FOR(i,0,n){
        int u, v, e;
        cin >> u >> v >> e;
        u--, v--;
        med[u][v] = e;
    }
    bfs(s, grid, h,w);
}

int main(){
    init();
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N = 1;
    //cin >> N;
    FOR(i,1, N + 1) solve(i);
    executeTime;
    return 0;
}

void init(){
    cerr << "Mood Try Winner ALL\n";

}
