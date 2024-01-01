#include <iostream>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
using namespace std;

#1번 풀이
int main(){
    fast;
    int key;cin >> key;
    //모듈러 연산으로 최적화 해준다.
    if(key>=0)key%=26;
    else key = -((-key)%26);
    cin.ignore();//버퍼 한 번 비워주고
    string word;
    getline(cin,word);//한줄 입력받기
    for(int i=0;i<word.size();i++){
        if(word[i]==' '){
            cout << ' ';
            continue;
        }
        int output = word[i] - key;
        if(output<65)output+=26;
        else if(output>90)output-=26;
        cout << (char)output;
    }
    return 0;
}


#2번 풀이
char Decryption(char src, int key){
    char ret = src;
    int repeat = abs(key);
    while(repeat--){
        if(key>0)ret--;
        else ret++;
        
        if(ret>90)ret-=26;
        else if(ret<65)ret+=26;
    }
    return ret;
}
int main(){
    fast;
    int key;
    string word;cin >> key;
    cin.ignore();
    getline(cin,word);
    for(int i=0;i<word.size();i++){
        if(word[i] == ' '){
            cout << ' ';
            continue;
        }
        cout << Decryption(word[i],key);
    }
    cout << endl;
    return 0;
}
