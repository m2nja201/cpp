#include <iostream>
using namespace std;

int main(){
    cout.tie(0);
    cin.tie(0);
    
    int L, P;
    int temp;
    cin >> L >> P;
    temp = L * P;
    
    int join[5];
    for (int i=0; i<5; i++){
        cin >> join[i];
    }
    
    for (int j=0; j<5; j++){
        cout << join[j] - temp;
        if (j != 4)
            cout << " ";
    }
    return 0;
}