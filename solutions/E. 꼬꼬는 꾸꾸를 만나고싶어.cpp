#include <iostream>
#define fast ios::sync_with_stdio(0),cin.tie(0)

#define endl '\n'
using namespace std;
int toMeet(int x,int y, int a, int b){
    int ret = (y-x)/(a+b);
    if((y-x)%(a+b))ret = -1;
    return ret;
}
int main(){
    fast;
    int testCase; cin >> testCase;
    while(testCase--){
        int x,y,a,b;cin >> x >> y >> a >> b;
        cout << toMeet(x, y, a, b) << endl;
    }
    return 0;
}
