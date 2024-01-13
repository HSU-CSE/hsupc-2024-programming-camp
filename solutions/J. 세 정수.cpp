#include <iostream>

using namespace std;

int solve1(int n) {
    int count = 0;
    for (int a = -n; a <= n; ++a) {
        for (int b = -n; b <= n; ++b) {
            int c = -2 * (a + b);
            if (abs(c) != 0 && abs(c) <= n) count++;
        }
    }
    return count + (2 * n + 1) * (2 * n + 1);
}

int solve2(int n) {
    int sum = 0;
    for (int k = 1; k <= n / 2; ++k) {
        sum += 2 * n + 1 - k;
    }
    return 2 * sum + (2 * n + 1) * (2 * n + 1);
}

int solve3(int n) {
    int answer = (2 * n + 1) * (2 * n + 1);
    int tmp = n / 2;
    answer += 2 * ((tmp * (2 * n + 1)) - (tmp * (tmp + 1) / 2));
    return answer;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve1(n);
    return 0;
}
