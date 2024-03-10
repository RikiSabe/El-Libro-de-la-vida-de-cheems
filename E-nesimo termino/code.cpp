// e - nesimo impar
ll e_nesimo_impar(ll i){
		return 1 + (i - 1) * 2;
}
// e - nesimo par
ll e_nesimo_par(ll i){
		return (i - 1) * 2;
}
// e - nesimo numero con todos los digitos pares
// Serie = 0, 2, 4, 6, 8, 20, 22, 24, 26, 28, 40....
string solve(ll n){
		n -= 1;
		string s ="";
		if ( n == 0) s += "0";
		while( n > 0){
				s = (char) (n%5 * 2 + '0') + s;
				n /= 5;
		}
		return s;
}
