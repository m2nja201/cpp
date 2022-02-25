// 0225

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    while (!commands.empty()){
        vector<int> temp;
        
        temp.reserve(commands.front()[1]-commands.front()[0]+1);
        for (int i=commands.front()[0]-1; i<commands.front()[1]; i++){
            temp.push_back(array[i]);
        }
        
        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands.front()[2]-1]);
        commands.erase(commands.begin());
    }
    
    return answer;
}