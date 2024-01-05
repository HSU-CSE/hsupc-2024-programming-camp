#include <algorithm>
#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
using namespace std;

//1번 STL 이용한 풀이
int compare(int &a, int &b) { return a < b; }

int main() {
  fast;
  int n, m;
  cin >> n >> m;
  vector<int> cats(n);
  vector<int> students(m);
  for (int i = 0; i < n; i++)
    cin >> cats[i];
  for (int i = 0; i < m; i++)
    cin >> students[i];

  sort(students.begin(), students.end(), compare); // 학생키 오름차순 정렬

  // 모든 고양이들의 키에 대해서 '착한인간구별공식' 을 만족하는 학생의 마지막 인덱스 파악
  for (int i = 0; i < n; i++) { // n
    int cat_height = cats[i];
    int cnt = upper_bound(students.begin(), students.end(), cat_height) - students.begin(); // logm
    cout << cnt << ' ';
  }
  cout << endl;
  return 0;
}

//2번 이분탐색 구현코드
#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'

using namespace std;

int compare(int &a,int &b){
    return a<b;
}

int upperBound(int target, vector<int>&array){
    int left= 0,right = array.size()-1;

    while(left<=right){//
        int mid = (left+right)/2;
        if(array[mid]> target){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }

    return left;
}
int main(){
    fast;
    int n,m; cin >> n >> m;
    vector<int>cats(n);
    vector<int>students(m);
    for(int i=0;i<n;i++)cin >> cats[i];
    for(int i=0;i<m;i++)cin >> students[i];

    sort(students.begin(),students.end(),compare); // 학생키 오름차순 정렬

    // 모든 고양이들의 키에 대해서 '착한인간구별공식' 을 만족하는 학생의 마지막 인덱스 파악
    for(int i=0;i<n;i++){//n
        int cat_height = cats[i];
        int cnt = upperBound(cats[i],students); //logm
        cout << cnt << ' ';
    }
    cout << endl;
    return 0;
}
