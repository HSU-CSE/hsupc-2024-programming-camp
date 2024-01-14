#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int answer = 0;
    for (int i = 0; i < n; i++) {
        char input[101];
        scanf("%s", input);

        char post = input[0];
        for (int j = 1; input[j] != '\0'; j++) {
            char cur = input[j];

            int diff = cur - post;
            if (diff < 0) diff += 7;
            if (diff != 2 && diff != 4 && diff != 6) {
                answer++;
                break;
            }

            post = cur;
        }
    }
    printf("%d", answer);

    return 0;
}
