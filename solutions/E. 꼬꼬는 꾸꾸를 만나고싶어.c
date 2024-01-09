#include <stdio.h>

int toMeet(int x, int y, int a, int b) {
    int ret = (y - x) / (a + b);
    if ((y - x) % (a + b)) ret = -1;

    return ret;
}

int main() {
    int testCase;
    scanf("%d", &testCase);

    for (int repeat = 0; repeat < testCase; repeat++) {
        int x, y, a, b;
        scanf("%d %d %d %d", &x, &y, &a, &b);
        printf("%d\n", toMeet(x, y, a, b));
    }

    return 0;
}
