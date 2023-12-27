#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
using namespace std;
bool compare(string& word,int idx){
  int i=idx;
  string compare ="Hong";
  for(;i-idx<compare.size() && i<word.size();i++){
    if(word[i]!=compare[i-idx])return false;
  }
  if(i!=idx+4)return false;
  return true;
}
int main(){
  fast;
  string word;cin >> word;
  int cnt=0;
  for(int i=0;i<word.size();i++){
    if(word[i]=='H'){
      bool ret = compare(word,i);
      if(ret){
        cnt++;
        i+=3;
      }
    }
  }
  cout << cnt;
}