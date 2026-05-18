#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;
const int N = 1e5 + 10;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

char g[405][405];
ll dis[405][405];
bool vis[405][405];

void solve(){
    int n, m;
    ll h;
    cin >> n >> m >> h;

    pair<int, int> S, T;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> g[i][j];
            dis[i][j] = INF;

            if(g[i][j] == 'S')
                S = {i, j};
            if(g[i][j] == 'T')
                T = {i, j};
        }
    }

    priority_queue<
        pair<ll, pair<int, int>>,
        vector<pair<ll, pair<int, int>>>,
        greater<pair<ll, pair<int, int>>>
    > pq;

    dis[S.first][S.second] = 0;
    pq.push({0, S});

    while(!pq.empty()){
        auto [d, pos] = pq.top();
        pq.pop();

        auto [x, y] = pos;

        if(vis[x][y])
            continue;
        vis[x][y] = true;

        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 1 || nx > n || ny < 1 || ny > m)
                continue;

            ll w = 0;

            if(g[nx][ny] >= '0' && g[nx][ny] <= '9')
                w = g[nx][ny] - '0';

            if(dis[nx][ny] > dis[x][y] + w){
                dis[nx][ny] = dis[x][y] + w;
                pq.push({dis[nx][ny], {nx, ny}});
            }
        }
    }

    if(h - dis[T.first][T.second] > 0)
        cout << "Yes\n";
    else
        cout << "No\n";

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            vis[i][j] = false;
            dis[i][j] = INF;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while(q--){
        solve();
    }

    return 0;
}
