#include <iostream>
using namespace std;

int cm(int *nb){
    int sum = 2;
    int len = 0;
    for (int i = 0; i < 4; i++){
        if (nb[i] == 10)
            continue;
        else{
            len++;
            if (nb[i] == 0) sum += 4;
            else if (nb[i] == 1) sum += 2;
            else sum += 3;
        }
    }
    sum += len - 1;
    return (sum);
}

void initialize(int *nb){
    for (int i = 0; i < 4; i++){
        nb[i] = 10;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int first = -1;
    int pos[4];
    bool flag = 1;
    while (1){
        cin >> first;
        if (first == 0) break;

        int num = first;
        if (num / 1000 == 0) {
            pos[0] = 10;
            flag = 0;
        }
        else pos[0] = num / 1000;
        num = num % 1000;

        if (num / 100 == 0) {
            if (flag == 0)
                pos[1] = 10;
            else pos[1] = 0;
        }
        else {
            pos[1] = num / 100;
            flag = 1;
        }
        num = num % 100;

        if (num / 10 == 0) {
            if (flag == 0)
                pos[2] = 10;
            else pos[2] = 0;
        }
        else {
            pos[2] = num / 10;
            flag = 1;
        }
        num = num % 10;

        pos[3] = num;
        cout << cm(pos) << "\n";
        initialize(pos);
    }
    return 0;
}