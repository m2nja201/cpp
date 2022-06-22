#include <iostream>
using namespace std;

int h_max = 23;
int m_max = 59;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    int h, m, time;
    cin >> h >> m >> time;

    m += time;
    if (m > m_max){
        h += m / 60;
        m = m % 60;
    }
    if (h > h_max){
        h -= 24;
    }

    cout << h << " " << m;

    return 0;
}