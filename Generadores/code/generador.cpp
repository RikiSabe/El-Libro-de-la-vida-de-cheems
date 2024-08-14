vector<string> gengrid(int n, int m, int percent = 25){
    // porcentaje de #
    vector<string> res;
    FOR(i,0,n){
        string s;
        FOR(j,0,m){
            int randcurr = rand() % 100;
            if( randcurr < percent ) s += '#'; //cout << "#";
            else s+= '.'; //cout << ".";
        }
        res.push_back(s);
    }
    return res;
}

vector<int> genarr(int n, int a, int b, bool binario = false){
    // al habilitar el binario, no importa [a,b]
    vector<int> res(n);
    FOR(i,0,n){
        if( binario ) res[i] = (rand() % 2 ? 1 : 0);
        else res[i] = (a + rand() % (b - a + 1));
    }
    return res;
}

string genstr(int n, char a, char b, bool binario = false){
    // al habilitar el binario, no importa [a,b]
    string s;
    FOR(i,0,n){
        if( binario ) s += (rand() % 2 ? '1' : '0');
        else s += (a + rand() % (b - a + 1));
    }
    return s;
}

int genint(int a, int b){
    return (a + rand() % (b - a + 1));
}

ll genll(ll a, ll b){
    return (a + rand() % (b - a + 1LL));
}

void solve(int testCase) {
    srand(time(NULL));
    // vector<string> grid = gengrid(10,30); // [n,m]
    // vector<int> a = genarr(10, 10, 20); // [n, [a,b], binary=false]
    // string s = genstr(30,'a', 'b'); // [n, [a,z], binario=false]
    // int x = genint(-1e4, 1e4); // [a,b]
    // ll y = genll(1e16, 1e18); // [a,b]
}
