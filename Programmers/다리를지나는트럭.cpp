#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, total_weight = 0, time = 0;
    int idx = 0; // 트럭 인덱스

    queue<int> bridge;

    for (int i = 0; i < bridge_length; i++) // 다리 크기만큼 채움
    {
        bridge.push(0);
    }

    while (idx < truck_weights.size()) { // 마지막 트럭이 다리에 올라갈 때까지
        answer++;
        
        // 1. 다리를 지났으면 큐에서 제거
        total_weight -= bridge.front();
        bridge.pop();
        
        // 2. 다리에 올라갈 수 있는 상태면 트럭을 다리에 올리기
        if (weight - total_weight >= truck_weights[idx]) { 
            bridge.push(truck_weights[idx]);
            total_weight += truck_weights[idx];
            idx++;
        }
        else { // 3. 다리에 올라갈 수 없다면 0 (그냥 빈 것!)
            bridge.push(0);
        }        
    }
    
    // 4. 마지막 트럭이 지날 때 필요한 시간
    answer += bridge_length;
    
    return answer;
}
