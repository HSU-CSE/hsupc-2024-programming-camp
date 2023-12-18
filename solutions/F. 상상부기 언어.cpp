#include <iostream>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
using namespace std;
/*
    
 */
int main() {
    fast;
    string a;
    getline(cin,a);//한줄 입력 받기
    for(int i=0;i<a.size();i++){
        if(a[i]<=63)a[i]-=32;
        int value=a[i]-196;
        while(value<0)value+=127;
        cout <<(char)value;
    }
    return 0;
}
