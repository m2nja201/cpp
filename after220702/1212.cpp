#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> base2;

void changeToBase2(string b8){
    int start = 0;
    for (int i= b8.length()-1; i >= 0; i--){
        int num = b8[i] - '0';
        for (int j = 0; j < 3; j++){
            base2.push_back(num % 2);
            num /= 2;
        }
    }

    reverse(base2.begin(), base2.end());

    for (int k = 0; k < base2.size(); k++){
        if (base2[k] == 1){
            start = k;
            break;
        }
    }

    for (int m = start; m < base2.size(); m++){
        cout << base2[m];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string base8;
    cin >> base8;

    if (base8 == "0"){
        cout << "0";
        return 0;
    }

    changeToBase2(base8);
    return 0;
}