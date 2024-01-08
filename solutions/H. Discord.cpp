#include <bits/stdc++.h>
using namespace std;

bool solve(string s) {
    char post = s[0];
    for (int i = 1; i < s.length(); i++) {
        char cur = s[i];
        int diff = cur - post;
        if (diff < 0) diff += 7;
        if (diff != 2 && diff != 4 && diff != 6) {
            return false;
        }
        post = cur;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        if (solve(s)) {
            answer++;
        }
    }
    cout << answer;

    return 0;
}