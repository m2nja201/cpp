#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0; // 최소 거리
    int del = 0;
    int pick = 0;
    
    for (int i = n-1; i >= 0; i--) { // 뒤에서부터 시작 (무조건 맨뒤까지 갔다가 돌아오면서 다른 작업 수행하는 게 최선)
        int back = 0; // 출발점을 찍어야 하는 횟수(리필)
        if (deliveries[i] != 0 || pickups[i] != 0) { // 작업해야할 게 있다면
            //cout << "시작 del : "<<del << " / 시작 pick : "<<pick << endl;
            while (del < deliveries[i] || pick < pickups[i]){ // 
                back++;
                del += cap;
                pick += cap;
            }
            //cout << "while 후 del : "<<del << " / while 후 pick : "<<pick << endl;
            del -= deliveries[i];
            pick -= pickups[i];
            //cout << "뺄셈 후 del : "<<del << " / 뺄셈 후 pick : "<<pick << endl;
        }
        answer += (i + 1) * dist * 2; // 왕복
        //cout << "dist : "<<dist << endl;
    }
    
    return answer;
}
