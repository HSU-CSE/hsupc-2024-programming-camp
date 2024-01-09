#include <stdio.h>

#define abs(x) (x > 0 ? x: -x)
const int ALPHABET_SIZE = 26;
int key;
char word[55];

void solve1() {
    // 키가 알파벳을 여러 번 돌게 되면 비효율적이므로 모듈러 연산으로 최적화
    if (key >= 0) {
        key = key % ALPHABET_SIZE;
    } else {
        key = abs(key) % ALPHABET_SIZE * -1;
    }

    for (int index = 0; word[index]; index++) {
        if (word[index] == ' ') {
            printf(" ");
            continue;
        }
        int output = word[index] - key;
        if (output < 'A') {
            output += ALPHABET_SIZE;
        } else if (output > 'Z') {
            output -= ALPHABET_SIZE;
        }
        printf("%c", (char) output);
    }
}

char decryption(char src, int key) {
    int ret = (int) src;

    // 음수면 앞으로 돌고 양수면 뒤로 돌아야 된다.
    for (int repeat = 0; repeat < abs(key); repeat++) {
        if (key < 0) {
            ret++;
        } else {
            ret--;
        }
        if (ret > 'Z') {
            ret -= ALPHABET_SIZE;
        } else if (ret < 'A') {
            ret += ALPHABET_SIZE;
        }
    }

    return (char) ret;
}

void solve2() {
    for (int index = 0; word[index]; index++) {
        if (word[index] == ' ') {  // 빈칸은 그냥 출력
            printf(" ");
            continue;
        }
        printf("%c", decryption(word[index], key));
    }
}

int main() {
    scanf("%d", &key);  // 키 입력 받기
    scanf("%[^\n]s", word);  // 한 줄 입력
    solve1();
    return 0;
}