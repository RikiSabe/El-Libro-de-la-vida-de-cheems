// Encontrar el minimo de pasos recorriendo todas las X desde A hasta B en grid
int dx[4]{-1, 0, 1, 0};
int dy[4]{0, 1, 0, -1};

int bfs(ii start, ii goal, vector<string> &grid, vector<ii> &equis, int n, int m){
    int totalx = equis.size();
    int allVisited = (1 << totalx) - 1;
    
    queue<tuple<int,int,int>> q;
    map<tuple<int,int,int>,int> dist;

    int startVisitedX = 0;
    FOR(i,0,totalx){
        if( start.first == equis[i].first && start.second == equis[i].second ){
            startVisitedX |= (1 << i);
        }
    }

    q.push({start.first, start.second, startVisitedX});
    dist[{start.first, start.second, startVisitedX}] = 0;

    while( !q.empty() ){
        tuple<int,int,int> curr = q.front(); 
        q.pop();
        int cx, cy, cvisitedx;
        tie(cx, cy, cvisitedx) = curr;
        int cdist = dist[{cx, cy, cvisitedx}];

        if( cx == goal.first && cy == goal.second && cvisitedx == allVisited ){ return cdist; }

        FOR(i,0,4){
            int xx = cx + dx[i];
            int yy = cy + dy[i];

            if( xx >= 0 && yy >= 0 && xx < n && yy < m && grid[xx][yy] != '#' ){
                int nvisitedx = cvisitedx;
                FOR(i,0,totalx){
                    if( xx == equis[i].first && yy == equis[i].second ){
                        nvisitedx |= (1 << i);
                    }
                }
                if( dist.find({xx, yy, nvisitedx}) == dist.end() ){
                    dist[{xx, yy, nvisitedx}] = cdist + 1;
                    q.push({xx, yy, nvisitedx});
                }
            }
        }
    }
    return -1;
}
