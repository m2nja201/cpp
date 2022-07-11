#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void print(vector<char> a, int R, string S){
    int len = R * S.length();
    for (int i = 0; i < len; i++){
        cout << a[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T, R; // T : 테스트 케이스 개수, R : 반복횟수
    string S;

    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> R >> S;
        vector<char> str;
        for (int k = 0; k < S.length(); k++){
            for (int j = 0; j < R; j++){
                str.push_back(S[k]);
            }
        }
        print(str, R, S);
        cout <<"\n";
    }
    return 0;
}