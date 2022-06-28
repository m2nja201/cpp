#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int M; // �ٲ� Ƚ��
    int x, y, tmp;
    int ball[3] = {1, 2, 3}; // ball[0] = 0+1�� �� ��ġ�� 1, ball[1] = 1+1�� �� ��ġ�� 2, ball[2] = 2+1�� �� ��ġ�� 3

    cin >> M;
    for(int i= 0; i< M; i++){
        cin >> x >> y;
        tmp = ball[x - 1];
        ball[x - 1] = ball[y - 1];
        ball[y - 1] = tmp;
    }

    for (int j = 0; j < 3; j++){
        if (ball[j] == 1){
            cout << j+1;
            break;
        }
    }
    return 0;
}