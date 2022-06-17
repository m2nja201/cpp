#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    vector<double> money;
    int x, y;
    int n;

    double min = 100000.0;
    cin >> x >> y >> n;
    
    money.push_back((double)x / (double)y * 1000.00); // ¼¼ºì 25
    for (int i = 0; i< n; i++){
        cin >> x >> y;
        money.push_back((double)x / (double)y * 1000.00);
    }

    for (int j = 0; j < n+1; j++){
        if (min > money[j]){
            min = money[j];
        }
    }

    printf("%.2f", min);
    return 0;
}