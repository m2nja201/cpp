// ³ª¸ÓÁö (10430)

#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    int A, B, C; 
    cin >> A >> B >> C;

    int num[4];
    num[0] = (A + B)%C;
    num[1] = ((A%C) + (B%C)) % C; 
    num[2] = (A * B) % C; 
    num[3] = ((A%C) * (B%C)) % C; 

    for (int i = 0; i < 4; i++){
        cout<<num[i]<<"\n";
    }
    return (0);
}