// Â÷Æ®(1239)

#include <iostream>
#define endl "\n"
using namespace std;

int N;
int arr[9]; // max : 8°³
int maxVal = -1;

void recursive(int depth)
{
    if (depth == N)
    {
        int temp = 
        maxVal = (maxVal > temp)? maxVal : temp;
    }
    else
    {
        
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    
    for (int i = 0; i< N; i++){
        cin >> arr[i];
    }
    recursive(0);

    return (0);
}