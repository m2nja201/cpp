#include <iostream>
using namespace std;

int play(char a, char b){
    if (a == b) return 0;
    if (a == 'R'){
        if (b == 'P') return 1; // player 2 win
        else if (b == 'S') return -1; // player 1 win
    }
    else if (a == 'P'){
        if (b == 'R') return -1;
        else if (b == 'S') return 1;
    }
    else if (a == 'S'){
        if (b == 'R') return 1;
        else if (b == 'P') return -1;
    }
    return 2; //err
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int total;
    cin >> total;
    for (int i = 0; i < total; i++){
        int n;
        int win1 = 0, win2 = 0;
        cin >> n;
        for (int j = 0; j < n; j++){
            char p1, p2;
            cin >> p1 >> p2;
            if (play(p1, p2) == 1) win2++;
            else if (play(p1, p2) == -1) win1++;
        }
        if (win2 > win1) cout << "Player 2\n";
        else if (win2 < win1) cout << "Player 1\n";
        else cout << "TIE\n";
    }
    return 0;
}