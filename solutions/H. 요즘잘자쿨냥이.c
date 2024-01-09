#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d ", &n, &m);

    int count = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            char customer, buffer;
            scanf("%c%c", &customer, &buffer);
            if (customer == 'C') {
                count++;
            }
        }
    }

    printf("%d", count);
    return 0;
}