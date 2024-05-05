ii arr[N];
int inp[N];
vector<int> tree[4*N];

void build(int node,int l,int r){
	if(l==r){
		tree[node].push_back( arr[l].second );
		return;
	}
	int m = (l+r)/2;
	build(2 * node,l,m);
	build(2 * node + 1,m+1,r);
	merge(tree[2 * node].begin(),tree[2 * node].end(),tree[2 * node + 1].begin(),tree[2 * node + 1].end(), back_inserter(tree[node]));
}
int qry(int node,int l,int r,int i,int j,int k){
	if(l==r){
		return tree[node][0];
	}
	int  m = (l+r)/2;
	int tot = upper_bound(tree[2 * node].begin(),tree[2 * node].end(),j) - lower_bound(tree[2 * node].begin(),tree[2 * node].end(),i);
	if(k>tot){
		return qry(2 * node + 1,m+1,r,i,j,k-tot);
	}
	return qry(2 * node,l,m,i,j,k);
}


void cumbia420PaLosCheems(int testCase) { /* ESTA VA POR CHEEMSITO :'v */
	int n, q; cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin>>arr[i].first;
		arr[i].second = i;
		inp[i] = arr[i].first;
	}
	sort(arr+1,arr+n+1);
	build(1,1,n);
	while(q--){
		int l,r,k; cin>>l>>r >> cin >> k;
		cout<<inp[ qry(1,1,n,l,r,k) ]<<endl;
	}
}
