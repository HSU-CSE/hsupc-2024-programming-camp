#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int count = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            char customer;
            cin >> customer;
            if (customer == 'C') {
                count++;
            }
        }
    }

    cout << count;
    return 0;
}