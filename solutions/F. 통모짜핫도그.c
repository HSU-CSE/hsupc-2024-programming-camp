#include <stdio.h>

#define max(a, b) (a > b ? a : b)

int main() {
    int n, s, d;
    scanf("%d", &n);
    scanf("%d %d", &s, &d);

    printf("YES\n");
    int end_point = s + d;
    for (int index = 0; index < n - 1; index++) {
        scanf("%d %d", &s, &d);
        if (s >= end_point) {
            printf("YES\n");
        } else {
            printf("No\n");
        }
        end_point = max(end_point, s + d);
    }

    return 0;
}
