#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const double eps = 1e-7;
const int N =  2e5 + 10;
bool check(int y){
    return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}
int cal(int y, int m, int d){
    int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int res = accumulate(a, a + m, 0) + d;
    if (check(y) && m >= 3) res++;
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int y, m, d;
    while (cin >> y >> m >> d) {
        cout << cal(y, m , d) << "\n";
    }
    return 0;
}
