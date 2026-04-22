#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
#define lowbit(x) (x) & (-x)
#define vec vector<int>
#define vvec vector<vector<int>>
#define rep(i, a, b) for(int i = (a); i <= (int)(b); ++i)
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double eps = 1e-7;
const int N =  2e5 + 10;
const int h[7][7] = {{2, 3, 0}, {4, 5, 6, 0}, {7, 8, 9, 10, 0}, {11, 12, 13, 0}, {14, 15, 0}};
const int v[7][7] = {{4, 11, 0}, {2, 8, 14, 0}, {1, 5, 12, 16, 0}, {3, 9, 15, 0}, {6, 13, 0}};
const int p[7][7] = {{1, 3, 6, 10, 0}, {2, 5, 9, 13, 0}, {4, 8, 12, 15, 0}, {7, 11, 14, 16, 0}};
const int q[7][7] = {{1, 2, 4, 7, 0}, {3, 5, 8, 11, 0}, {6, 9, 12, 14, 0}, {10, 13, 15, 16, 0}};
bool f[1 << 16];
vector<int> state;
void init(){
    for (int i = 0; i < 16; i++) {
        state.push_back(1 << i);
    }
    //横向
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            if (h[i][j] == 0) break;
            int m = 1 << (h[i][j] - 1);
            for (int k = 1; k < 3; k++) {
                if (h[i][j + k] == 0) break;
                m |= 1 << (h[i][j + k] - 1);
                state.push_back(m);
            }
        }
    }
    //纵向
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            if (v[i][j] == 0) break;
            int m = 1 << (v[i][j] - 1);
            for (int k = 1; k < 3; k++) {
                if (v[i][j + k] == 0) break;
                m |= 1 << (v[i][j + k] - 1);
                state.push_back(m);
            }
        }
    }
    //135
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            if (p[i][j] == 0) break;
            int m = 1 << (p[i][j] - 1);
            for (int k = 1; k < 3; k++) {
                if (p[i][j + k] == 0) break;
                m |= 1 << (p[i][j + k] - 1);
                state.push_back(m);
            }
        }
    }
    //45
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            if (q[i][j] == 0) break;
            int m = 1 << (q[i][j] - 1);
            for (int k = 1; k < 3; k++) {
                if (q[i][j + k] == 0) break;
                m |= 1 << (q[i][j + k] - 1);
                state.push_back(m);
            }
        }
    }
    for (int s = 1; s <= ((1 << 16) - 1); s++) { 
        f[s] = false;
        for (int m : state) {
            if ((s & m) == m) { 
                if (!f[s ^ m]) { 
                    f[s] = true; break;
                }
            }
        }
    }
}
void solve(){
    string s;
    int mask = 0;
    for (int i = 0; i < 16; i++) {
        cin >> s;
        if (s == ".") mask |= 1 << i;
    }
    if (f[mask]) cout << "Alice\n";
    else cout << "Bob\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
