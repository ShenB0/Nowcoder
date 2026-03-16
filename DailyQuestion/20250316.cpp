#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const int N = 1e3 + 5;
const ll INF = 1LL << 60;
char a[N][N], b[N][N], c[N][N];
void solve(){
    int X, Y, Z, n;
    cin >> X >> Y >> Z >> n;
    memset(a, '.', sizeof(a));
    memset(b, '.', sizeof(b));
    memset(c, '.', sizeof(c));
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[y][x] = 'x';
        b[y][z] = 'x';
        c[z][x] = 'x';
    }
    for (int i = Y; i >= 1; i--) {
        for (int j = 1; j <= X; j++) {
            cout << a[i][j];
        }
        cout << " ";
        for (int j = 1; j <= Z; j++) {
            cout << b[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 1; i <= Z; i++) {
        for (int j = 1; j <= X; j++) {
            cout << c[i][j];
        }
        cout << "\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
    
