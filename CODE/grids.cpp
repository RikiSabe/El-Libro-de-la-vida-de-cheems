// knight moves...
// int dx[] = {-1,-2,-2,-1,1,2,2,1};
// int dy[] = {-2,-1,1,2,2,1,-1,-2};
 
// grid moves without diagonal
// int dx[] = {0,-1,0,1};
// int dy[] = {-1,0,1,0};
 
// only all diagonal moves
// int dx[] = {-1,-1,1,1};
// int dy[] = {-1,1,1,-1};
 
// grid moves with diagonal
// int dx[] = {0,-1,-1,-1,0,1,1,1};
// int dy[] = {-1,-1,0,1,1,1,0,-1};

bool ok(int cx, int cy, int n, int m){
    return cx >=0 && cy >= 0 && cx < n && cy < m;
}

void bfs(ii i, vector<string> &grid, vector<vector<bool>> &visited, int n, int m){
    visited[i.first][i.second] = true;
    queue<ii> q;
    q.push(i);
    //options
    // int dis = 1;
    // int dis[n][m];
    // dis[i.first][i.second] = 1;
    while(!q.empty()){
        int cx = q.front().first, cy = q.front().second;
        q.pop();
        FOR(i,0,4){
            int xx = cx + dx[i];
            int yy = cy + dy[i];
            // cout << cx << " " <<  cy << nl;
            if( !ok(xx,yy,n,m) ) continue;
            if( grid[xx][yy] == '.' && !visited[xx][yy]){
                visited[xx][yy] = true;
                // dis++;
                // dis[xx][xx] = dis[cx][cy] + 1;
                q.push({xx,yy});
            }
        }
    }
}
