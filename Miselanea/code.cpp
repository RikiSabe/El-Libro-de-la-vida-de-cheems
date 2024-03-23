// verificar si un año es biciesto
bool biciesto(int a){
  return (a%4==0 && a%10!=0) || (a%400==0);
}
// valor maximo = 24 * 60
// 6:13 -> 8:00 = 1:47
void distance(){
		int time, h ,m;
		cin >> h >> m;
		time = 60 * h + m;
		cin >> h >> m;
		int t = 60 * h + m - time;
		if( t < 0 ) t += 24 * 60;
		cout << t/60 << ":" << t%60 << nl;
}
// dias de los meses
int mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// verificar palindromo F1
bool ok(int p){
    int res = 0,num = p;
    while(p>0){
        res=(res+p%10)*10; p/=10;
    }
    res /= 10;
    return num == res;
}
// verificar palindromo F2
bool ok(int n){
	vector<int> p;
	while(n>0){
		p.push_back(n%10); n/=10;
	}
	for( int i=0 ; i<p.size() ; i++){
		if(p[i] != p[p.size()-1-i]) return false;
	}
	return true;
}
// verificar palindromo F3
bool ok(string s){
	for( int i=0 ; i<s.length()/2 ; i++){
		if(s[i] != s[s.length()-1-i]) return false;
	}
	return true;
}
// reduccion de fracciones
int gcd(int a, int b){
	if ( b == 0) return a;
	return gcd( b, a % b );
}
void reduccion(int n,int d){
	int mcd = gcd(n,d);
	n /= mcd; d /= mcd;
	if ( d == 1 ) cout << n << endl;
	else cout << n << "/" << d << endl;
}
// knight moves...
int dx[] = {-1,-2,-2,-1,1,2,2,1};
int dy[] = {-2,-1,1,2,2,1,-1,-2};
// grid moves without diagonal
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
// only all diagonal moves
int dx[] = {-1,-1,1,1};
int dy[] = {-1,1,1,-1};
// grid moves with diagonal
int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {-1,-1,0,1,1,1,0,-1};

// Armar el minimo numero de una lista
// condiciones: vecinos diferentes, sin zeros a la izq
void solve(int ith){
    int a[10] = {0};
    int sum = 0;
    FOR(i,0,10) cin >> a[i], sum += a[i];
    bool ok = true;
    if( 2 * a[0] > sum ) ok = false;
    FOR(i,1,10){
        if( 2 * a[i] - 1 > sum ) ok = false;
    }
    if( a[0] == 1 && sum == 1 ){
        cout << 0 << nl;
        return;
    }
    if( !ok ) {
        cout << -1 << nl;
        return;
    }
    int pre = 0;
    while( sum ){
        int curr = 10;
        FOR(i,0,10){
            if( i == pre || a[i] == 0) continue;
            if( a[i] * 2 > sum ){
                curr = i;
                break;
            }
            curr = min(i,curr);
        }
        pre = curr, a[curr]--, sum--;
        cout << curr;
    }
    cout << nl;
}
