#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    int count = 0;
    for (int a = -n; a <= n; ++a) {
        if (a == 0) continue;
        for (int b = -n; b <= n; ++b) {
            int c = -2 * (a + b);
            if (abs(c) <= n) count++;
        }
    }
    return count + (2 * n + 1) * (2 * n + 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}
