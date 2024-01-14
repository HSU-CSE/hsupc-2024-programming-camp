#include <stdio.h>

#define abs(x) (x > 0 ? x : -x)

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
    int sum = (n / 2 * (2 * n + 1)) - (n / 2 * (n / 2 + 1) / 2);
    return 2 * sum + (2 * n + 1) * (2 * n + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", solve1(n));
    return 0;
}
