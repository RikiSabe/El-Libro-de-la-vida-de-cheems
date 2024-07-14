int contarNumerosConDigitoHasta(int num, int d) {
    if (num < 0) return 0;
    string s = to_string(num);
    int digitos = s.size();
    
    vector<vector<int>> dp(digitos + 1, vector<int>(2, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= digitos; ++i) {
        int limite = s[i - 1] - '0';
        for (int j = 0; j < 2; ++j) {
            for (int digito = 0; digito <= (j ? 9 : limite); ++digito) {
                if (digito == d) continue;
                dp[i][j || (digito < limite)] += dp[i - 1][j];
            }
        }
    }
    
    return dp[digitos][1];
}

// Función para contar cuántos números desde 1 hasta n tienen al menos un dígito 'd'
int contarNumerosConDigito(int n, int d) {
    if (n < 0) return 0;
    return contarNumerosConDigitoHasta(n, d);
}
