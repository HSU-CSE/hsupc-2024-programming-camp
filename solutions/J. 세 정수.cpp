#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
    int count = 0;
    for (int a = -n; a <= n; ++a) {
        for (int b = -n; b <= n; ++b) {
            int c = -2 * (a + b);
            if (abs(c) != 0 && abs(c) <= n) count++;
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
