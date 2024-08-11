// Minimo de caracteres que puedes agregar en cualquier posición para formar un palindromo
int fun(string s){
    int n = s.size();
    vector<vector<int>> dp(n, vector<int> (n,0));
    FOR(l,2,n + 1){
        FOR(i,0,n - l + 1){
            int j = i + l - 1;
            if( s[i] == s[j] ){
                dp[i][j] = dp[i + 1][j - 1];
            }else{
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
            }
        }
    }
    return dp[0][n-1];
}
