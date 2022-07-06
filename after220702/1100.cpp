#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    char pos;
    int num = 0;
    for (int i = 0; i < 8; i++){
        if (i % 2 == 0){ // 흰으로 시작
            for (int j = 0; j < 8; j++){
                cin >> pos;
                if ((j % 2 == 0) && (pos == 'F')) num++;
            }
        }
        else { // 검으로 시작
            for (int j = 0; j < 8; j++){
                cin >> pos;
                if ((j % 2 == 1) && (pos == 'F')) num++;
            }
        }
    }
    cout << num;
    return 0;
}