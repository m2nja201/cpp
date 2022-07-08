// ³ª¸ÓÁö

#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    int arr[42]={0};
    int n;
    int diff = 0;

    for (int i = 0; i < 10; i++){
        cin >> n;
        arr[n % 42]++;
    }

    for (int j = 0; j < 42; j++){
        if (arr[j] != 0)
            diff++;
    }
    cout << diff;
    return 0;
}