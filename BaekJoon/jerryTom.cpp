#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    int A, B;
    cin>>A>>B; 

    int ans = 0;
    ans = B - A;

    cout<<ans <<" "<<B; 
    return (0);
}