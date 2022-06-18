#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    int n;
    int num[3];
    int max = 0;
    cin >> n;
    vector<int> arr(n);

    for (int i =0; i< n; i++){
        int tmp;
        for (int j = 0; j < 3; j++){
            cin >> num[j];
        }

        sort(num, num+3);
        for (int j = 0; j < 3; j++){
            int cnt = 0;
            for (int k = j; k < 3; k++){
                if (num[k] == num[j]){
                    cnt++;
                    //cout << "num[j] = "<<num[j] << " num[k] = "<<num[k] <<"\n";
                }
            }
            if (j == 2) arr[j] = num[j] * 100;
            if (cnt == 3) {
                //cout << "cnt == 3 ## ";
                arr[j] = 10000 + num[j] * 1000;
                break;
            }
            else if (cnt == 2) {
                //cout << "cnt == 2 ## ";
                arr[j] = 1000 + num[j] * 100;
                break;
            }
        }
    }
    
    cout <<"---------------\n";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<"\n";
    }
    cout <<"---------------\n";
    for(int y = 0; y < n; y++){
        if (max < arr[y]){
            max = arr[y];
        }
    }
    cout<<max;
    return 0;
}