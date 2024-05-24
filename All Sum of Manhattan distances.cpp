int distancesum(int arr[], int n) {
    sort(arr, arr + n);
    int res = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        res += (arr[i] * i - sum);
        sum += arr[i];
    }
 
    return res;
}
 
int totaldistancesum(int x[], int y[], int n)
{
    return distancesum(x, n) + distancesum(y, n);
}
 
int main()
{
    int x[] = { -1, 1, 3, 2 };
    int y[] = { 5, 6, 5, 3 };
    int n = sizeof(x) / sizeof(x[0]);
    cout << totaldistancesum(x, y, n) << endl;
    return 0;
}
