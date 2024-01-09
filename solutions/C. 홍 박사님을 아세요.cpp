#include <iostream>

using namespace std;

string word;

void solve() {
    int count = 0;
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == 'H') {
            count++;
        }
    }
    cout << count;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> word;
    solve();
    return 0;
}