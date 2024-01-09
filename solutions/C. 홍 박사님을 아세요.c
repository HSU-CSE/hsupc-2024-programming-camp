#include <stdio.h>

char word[102];

void solve() {
    int count = 0;
    for (int i = 0; word[i]; i++) {
        if (word[i] == 'H') {
            count++;
        }
    }
    printf("%d", count);
}

int main() {
    scanf("%s", word);
    solve();
    return 0;
}