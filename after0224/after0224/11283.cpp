#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int num;
    int total = 0;
    for (int i=0; i<5; i++){
        cin >> num;
        total += num * num;
    }
    cout << total % 10;
    return 0;
}