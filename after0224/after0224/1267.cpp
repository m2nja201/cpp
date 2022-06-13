#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, T; // N : 통화의 개수, T : 통화 시간
    int Y = 0;
    int M = 0;
    
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> T;
        Y += (T / 30 + 1);
        M += (T / 60 + 1);
    }

    Y *= 10;
    M *= 15;
    
    if (Y > M) cout << "M "<< M;
    else if (Y == M) cout << "Y M "<< Y;
    else cout << "Y "<< Y;
    
    return 0;
}