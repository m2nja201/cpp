#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    unsigned int n1, n2;
    int pos[2][2];
    int disx = 0;
    int disy = 0;
    
    cin >> n1 >> n2;
    pos[0][0] = (n1 - 1) / 4; // n1's x (0 ~ )
    pos[0][1] = (n1 % 4 == 0) ? 3 : (n1 - 1) % 4; // n1's y 
    pos[1][0] = (n2 - 1) / 4;
    pos[1][1] = (n2 % 4 == 0) ? 3 : (n2 - 1) % 4;
    
    // (3, 3) / (9, 1)
    disx = pos[1][0] - pos[0][0]; // 8 - 2 = 6
    disy = pos[1][1] - pos[0][1]; // 2 - 0 = 2
    
    disx = (disx < 0) ? -disx : disx;
    disy = (disy < 0) ? -disy : disy;
    cout << disx + disy;
    
    return 0;
}