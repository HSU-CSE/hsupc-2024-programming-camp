#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> cats;
vector<int> students;

int compare(int &a, int &b) {
    return a < b;
}

void solve1() {
    for (int index = 0; index < n; index++) { // n
        int cat_height = cats[index];
        int cnt = upper_bound(students.begin(), students.end(), cat_height) - students.begin(); // logm
        cout << cnt << ' ';
    }
    cout << endl;
}

int upperBound(int target, vector<int> &Array) {
    int left = 0, right = Array.size() - 1;

    while (left <= right) {//
        int mid = (left + right) / 2;
        if (Array[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}


void solve2() {
    // 모든 고양이들의 키에 대해서 '착한인간구별공식' 을 만족하는 학생의 마지막 인덱스 파악
    for (int index = 0; index < n; index++) {
        int cat_height = cats[index];
        int count = upperBound(cat_height, students);
        cout << count << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    cats.resize(n);
    students.resize(m);

    for (int index = 0; index < n; index++) {
        cin >> cats[index];
    }

    for (int index = 0; index < m; index++) {
        cin >> students[index];
    }

    sort(students.begin(), students.end(), compare); // 학생키 오름차순 정렬

    solve1();

    return 0;
}
