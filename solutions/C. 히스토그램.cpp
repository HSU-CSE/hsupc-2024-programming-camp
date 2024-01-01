#include<iostream>
#include<vector>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'

using namespace std;
int main(){
    fast;
    int n; cin >> n;
    vector<int>array(n);
    int max_height=0;
    for(auto&index:array){
        cin >>index;
        max_height=max(max_height,index);
    }
    
    for(int height = max_height;height>0;height--){
        for(auto value:array){
            char output = ' ';
            if(value>=height)output = value + '0';
            cout << output;
        }
        cout << endl;
    }

    
    
}
