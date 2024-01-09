#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> Array;

void solve() {
    int max_height = 0;
    for (int index = 0; index < N; index++) {
        cin >> Array[index];
        max_height = max(max_height, Array[index]);
    }

    for (int height = max_height; height >= 1; height--) {
        for (int index = 0; index < N; index++) {
            char output;
            if (Array[index] >= height) {
                output = (char) (Array[index] + '0');
            } else {
                output = ' ';
            }
            cout << output;
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    Array.resize(N);
    solve();
    return 0;
}
