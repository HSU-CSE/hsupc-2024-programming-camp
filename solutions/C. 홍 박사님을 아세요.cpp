#include <iostream>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
using namespace std;
//1번 풀이
int main(){
  fast;
  string word;cin >> word;
  int cnt=0;
  for(int i=0;i<word.size();i++){
    if(word[i]=='H'){
      cnt++;
    }
  }
  cout << cnt;
}
//2번 풀이
int main(){
  fast;
  string word;cin >> word;
  int cnt=0;
  for(int i=0;i<word.size();i++){
    cnt+=word[i]='H';
  }
  cout << cnt;
}