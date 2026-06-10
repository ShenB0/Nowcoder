#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;

#define debug(x) cout << #x << " = " << x << endl;
#define lowbit(x) (x) & (-x)
#define ALL(x) (x).begin(), (x).end()

const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double eps = 1e-7;
const int N = 5e5;

bool is_prime[N + 5];
vector<int> prime;

void init(){
    memset(is_prime, 1, sizeof(is_prime));

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N + 2; i++) {
        if (is_prime[i]) prime.push_back(i);
        for (auto p : prime) {
            if (p * i > (N + 2)) break;
            is_prime[p * i] = false;
            if (i % p == 0) break;
        }
    }
}

void solve(){
    init();

    int n;
    cin >> n;
    
    int cnt = 0;
    for (auto p : prime) {
        int b = p * p - 2;

        if (b > n) break;
        if (p == 2) cnt++;
        else if (is_prime[b]) cnt += 2;
    }

    cout << cnt << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (t--) solve();
    
    return 0;
}
