#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input;
    cin >> input;

    int result = 0;

    for (int i = 0; input[i]; i++)
    {
        if (input[i] >= 'A' && input[i] <= 'F')
        {
            result = result * 16 + input[i] - 'A' + 10;
        }
        else
            result = result * 16 + input[i] - '0';
    }
    cout<<result;
    return 0;
}