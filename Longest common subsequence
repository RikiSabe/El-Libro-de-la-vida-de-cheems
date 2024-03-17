int dp[N][N]; 

int LCS(string X, string Y, int m, int n) { // m = |X|, n = |Y|
  
    FOR(i, 0, m + 1) { 
        FOR(j, 0, n + 1) { 
           	if(i == 0 || j == 0) 
                dp[i][j] = 0; 
  
            else if (X[i - 1] == Y[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1] + 1; 
  
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
        } 
    } 

    return dp[m][n]; 
} 
