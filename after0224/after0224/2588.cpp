#include <iostream>
using namespace std;

void print(int *arr){
    for(int i = 0; i < 4; i++){
        cout << arr[i] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int num1, num2;
    int prt[4];
    
    cin >> num1 >> num2;
    prt[0] = num1 * (num2 % 10);
    prt[1] = num1 * ((num2 % 100)/10);
    prt[2] = num1 * (num2 / 100);
    prt[3] = prt[0] + prt[1] * 10 + prt[2] * 100;

    print(prt);

    return 0;
}