#include <string>
#include <vector>
#include <iostream>

using namespace std;

int num(string str){
    string total ="";
    if(str == "zero") return 0;
    else if (str=="one") return 1;
    else if(str=="two") return 2;
    else if (str=="three") return 3;
    else if (str == "four") return 4;
    else if (str == "five") return 5;
    else if (str == "six") return 6;
    else if (str == "seven") return 7;
    else if (str == "eight") return 8;
    else if (str == "nine") return 9;
    else return (-1);
}

int solution(string s) {
    int answer = 0;
    vector<int> temp;
    string str ="";
    
    for (int i=0; i<s.length(); i++){
        if (s[i]>=48 && s[i] <= 57){
            temp.push_back(s[i]-'0');
            continue;
        }
        else{
            str = str+s[i];
            cout<<str<<"  ";
            if (num(str) != -1){
                temp.push_back(num(str));
                str="";
            }
        }
    }
    
    int i =1;
    while (!temp.empty()){
        answer += temp.back() * i;
        i *= 10;
        temp.pop_back();
    }
    
    return answer;
}