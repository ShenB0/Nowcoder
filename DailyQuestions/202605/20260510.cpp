#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6;
int main() {
    int n;
    cin >> n;
    vector<bool> vis(1e6 + 1, false);
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    auto check = [&](ll x) -> bool{
        for (int i = 0; i < n; i++) {
            if (x * x * x + a[i] * x * x + b[i] * x + c[i] == 0) {
                return false;
            }  
        } 
        return true;
    };

    std::random_device rd;             
    std::mt19937 gen(rd());         
    std::uniform_int_distribution<> dis(0, 1e6);  

    while (true) {
        ll x = dis(gen);
        if (vis[x] && check(x)) {
            cout << x << "\n";
            return 0;
        } else {
            vis[x] = true;
        }
    }
}
