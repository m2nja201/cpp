#include <string>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> coms, bool *visited, int i) {
    visited[i] = true; // 해당 컴퓨터 방문 처리
    
    for (int j = 0; j < coms.size(); j++) {
        if (j == i) continue;
        if (coms[i][j] == 1 && visited[j] == false) {
            // 서로 연결되어 있고, 방문하지 않은 컴퓨터라면
            DFS(coms, visited, j);
        }    
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool *visited = new bool[n]; // 컴퓨터 방문했는지 check
    fill(visited, visited + n, false); // false로 초기화
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) { // 방문하지 않은 것에 대해
            DFS(computers, visited, i); 
            answer++; // DFS 하나가 끝나고 나면 answer 증가
        }
    }
    
    return answer;
}
