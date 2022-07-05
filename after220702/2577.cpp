#include <iostream>
#include <vector>
using namespace std;

vector<int> num = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void putnbr(int total){
    while (total != 0){
        num[total % 10]++;
        total /= 10;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int A, B, C;
    int total;
    cin >> A >> B >> C;
    total = A * B * C;

    putnbr(total);

    for (int i = 0; i < num.size(); i++){
        cout << num[i] << "\n";
    }

    return 0;
}