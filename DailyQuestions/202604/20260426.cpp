//𝑓(𝑥,𝑦)=𝑥+𝑦−(𝑥⊕𝑦)
// 通过二进制运算的性质，可以推导出 𝑓(𝑥,𝑦)=2×(𝑥&𝑦)
// 这是因为 𝑥+𝑦=(𝑥⊕𝑦)+2×(𝑥&𝑦)，所以 𝑓(𝑥,𝑦)=2×(𝑥&𝑦)
// 序列运算的性质：
// 需要计算的是从左到右依次应用 f 运算的结果。
// 例如，对于序列 𝑎1,𝑎2,𝑎3 ，计算 𝑓(𝑓(𝑎1,𝑎2),𝑎3)
// 可以观察到，f 运算的结果是前一次结果的按位与的两倍。
// 使用一个变量 result 初始化为序列的第一个元素。
// 从第二个元素开始，依次计算 𝑓(result,𝑎𝑖)并更新 result。
// 最终输出 result。
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l, r;
    cin >> l >> r;
    ll cur = a[1];
    for (int i = 2; i <= n; i++) {
        cur = (cur & a[i]) << 1;
        if (cur == 0) break;
    }
    cout << cur << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
