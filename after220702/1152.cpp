#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int cnt = 0;
    string sen;

    getline(cin, sen);
    int len = sen.length();
    cout << "len == "<<len<<endl;
    for (int i = 0; i < len; i++){
        if (i == 0 && sen[0] != ' ') { // �� �ձ��ڰ� ���� X
            cnt++;
            cout <<"�� ���ڰ� �ܾ� ����\n";
            continue;
        }
        cout << "sen[i] == "<<sen[i] <<endl;
        if (sen[i] == ' '){
            if (i+1 == len) break;
            if ((sen[i+1] >= 'a' && sen[i+1] <= 'z') || (sen[i+1] >= 'A' && sen[i+1] <= 'Z')){
                cnt++;
                i++;
                cout << "�ش� ���ڰ� �����̰� �� ���ڰ� �ܾ� �����϶�\n";
            }
        }
    }

    cout << cnt;
    return 0;
}