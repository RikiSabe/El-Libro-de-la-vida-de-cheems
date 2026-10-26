/*
 * Returns the number of subarrays with an odd sum in O(k) time,
 * given the positions of the 1s (vector A) and array size n. Indexed by 1

   n = 7,  A = [2, 5, 6]
   {0, 1, 0, 0, 1, 1, 0}
 */
ll countOdd(vector<ll> A, ll n) {
    ll sumOdd = 0LL, sumEven = 0LL;
    
    vector<ll> P; P.pb(0LL);
    for (int a : A) P.pb(a);
    P.pb(n + 1);

    FOR (i, 0, P.size() - 1) {
        ll sz = P[i + 1] - P[i];
        if (i % 2 == 0) sumEven += sz;
        else sumOdd += sz;    
    }

    return (sumEven * sumOdd);
}
