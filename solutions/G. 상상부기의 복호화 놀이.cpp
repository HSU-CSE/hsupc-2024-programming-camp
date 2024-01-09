#include <iostream>

using namespace std;
const int ALPHABET_SIZE = 26;
int key;
string word;

void solve1() {
    //모듈러 연산으로 최적화 해준다.
    if (key >= 0) {
        key = key % ALPHABET_SIZE;
    } else {
        key = abs(key) % ALPHABET_SIZE * -1;
    }

    for (int i = 0; i < word.size(); i++) {
        if (word[i] == ' ') {
            cout << ' ';
            continue;
        }
        int output = word[i] - key;
        if (output < 'A') {
            output += ALPHABET_SIZE;
        } else if (output > 'Z') {
            output -= ALPHABET_SIZE;
        }

        cout << (char) output;
    }
}


char decryption(char src, int key) {
    int ret = (int) src;

    for (int repeat = 0; repeat < abs(key); repeat++) {
        if (key > 0) {
            ret--;
        } else {
            ret++;
        }
        if (ret > 90) {
            ret -= ALPHABET_SIZE;
        } else if (ret < 65) {
            ret += ALPHABET_SIZE;
        }
    }

    return (char) ret;
}

void solve2() {
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == ' ') {
            cout << ' ';
            continue;
        }
        cout << decryption(word[i], key);
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> key;
    cin.ignore();
    getline(cin, word);
    solve1();
    return 0;
}