#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());

    int start = 0;
    int temp = 0;
    while (!numbers.empty()){
        temp = numbers.back();
        //cout<<"start vs numbers"<<start<<"   "<<numbers.front()<<endl;
        if (start == numbers.front()){
            start++;
            numbers.erase(numbers.begin());
        }
        else {
            answer += start;
            start++;
        }
    }
    
    while (temp<9){
        answer+=start;
        //cout<<"start vs numbers"<<start<<"   "<<numbers.front()<<endl;
        start++;
        temp++;
    }
    
    return answer;
}