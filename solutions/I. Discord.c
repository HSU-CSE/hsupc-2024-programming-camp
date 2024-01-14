#include <stdio.h>

int solve(string s) {
    char post = s[0];
    for (int i = 1; i < s.length(); i++) {
        char cur = s[i];
        
        int diff = cur - post;
        if (diff < 0) diff += 7;
        if (diff != 2 && diff != 4 && diff != 6) {
            return 1;
        }
        
        post = cur;
    }
    return 0;
}

int main() {
    int N;
    cin >> N;

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        if (solve(s)==1) {
            answer++;
        }
    }
    cout << answer;

    return 0;
}
