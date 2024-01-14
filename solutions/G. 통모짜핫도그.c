#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, s, d;
    cin >> n;
    int answer = 0;
    int end_point = s + d;
    for (int i = 0; i < n; i++) {
        cin >> s >> d;
	if (i == 0){
	    answer ++;
	    end_point = s + d;
	}
       else if(s >= end_point) {
            answer ++;
	    end_point = s + d;
        }
    }
    cout << answer << endl;
    return 0;
}
