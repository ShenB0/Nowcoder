#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        if (x % 4 != 0) cout << "Alice\n";
        else cout << "Bob\n";
    }
}
// 64 位输出请用 printf("%lld")
