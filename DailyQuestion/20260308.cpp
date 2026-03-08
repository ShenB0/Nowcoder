#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
void dfs(ll p, ll q){
    ll rem = p % q, quo = p / q;
    cout << quo;
    if (rem) {
        cout << "+1/";
        if (q % rem != 0) cout << "{"; 
        dfs(q, rem);
        if (q % rem != 0) cout << "}";
    }
}
void solve(){
    ll p, q;
    cin >> p >> q;
    cout << p << "/" << q << " = ";
    dfs(p, q);
    cout << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
