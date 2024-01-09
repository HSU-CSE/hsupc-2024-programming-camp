#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, s, d;
    cin >> n;
    cin >> s >> d;

    cout << "YES" << endl;
    int end_point = s + d;
    for (int i = 0; i < n - 1; i++) {
        cin >> s >> d;
        if (s >= end_point) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        end_point = max(end_point, s + d);
    }
    
    return 0;
}