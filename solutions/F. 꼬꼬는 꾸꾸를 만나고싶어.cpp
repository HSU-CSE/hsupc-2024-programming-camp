#include <iostream>

using namespace std;

int toMeet(int x, int y, int a, int b) {
    int ret = (y - x) / (a + b);
    if ((y - x) % (a + b)) ret = -1;
    return ret;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testCase;
    cin >> testCase;

    for (int repeat = 0; repeat < testCase; repeat++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        cout << toMeet(x, y, a, b) << endl;
    }

    return 0;
}
