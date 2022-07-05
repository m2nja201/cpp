#include <iostream>
using namespace std;

void counting(string t){
    int sum = 0;
    int db = 0;

    for (int i = 0; i < t.length(); i++){
        if (t[i] == 'O'){
            if (db != 0){
                db++;
                sum += db;
            }
            else {
                sum += 1;
                db = 1;
            }
        }
        else {
            db = 0;
        }
    }
    cout << sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++){
        string test;
        cin >> test;
        counting(test);
    }
    return 0;
}