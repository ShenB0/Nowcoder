#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll y;
    while (cin >> y) {
        ll d = y - 2018;
        ll tian = ((4 + d) % 10 + 10) % 10 + 1;
        ll di = ((10 + d) % 12 + 12) % 12 + 1;
        cout << tian << " " << di << "\n";
    }
}
