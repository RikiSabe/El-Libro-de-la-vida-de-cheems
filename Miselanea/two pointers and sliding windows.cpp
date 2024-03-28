// maxL -> maxlength subarray (sum < k)
int l = 0, r = 0, sum = 0, maxL = 0;
while( r < n ){
    sum += v[r];
    if( sum > k ){
        sum -= v[l];
        l++;
    }
    if( sum <= k ){
        maxL = max(maxL, r - l + 1);
    }
    r++;
} // cout << maxL << endl;
