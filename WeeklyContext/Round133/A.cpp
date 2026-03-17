#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
const int N = 2e5 + 5;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    s.erase(s.begin());
    s.erase(prev(s.end()));
    cout << "</" + s  + ">" << "\n";
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
    
