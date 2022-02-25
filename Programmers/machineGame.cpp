#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> store;
    int index = 0;
    
    while(!moves.empty()){
        int ii;
        bool flag = false;
        for (int i=0; i<board.size(); i++){
            if (board[i][moves.front()-1] != 0){
                ii = i;
                flag = true;
                break;
            }
        }
        if (!flag){
            moves.erase(moves.begin());
        }
        else{
            if (!store.empty()){
                if (store.back() == board[ii][moves.front()-1]){
                    answer += 2;
                    store.pop_back();
                    board[ii][moves.front()-1] = 0;
                    moves.erase(moves.begin());
                    continue;
                }
            }
            store.push_back(board[ii][moves.front()-1]);
            board[ii][moves.front()-1] = 0;
            moves.erase(moves.begin());
        }
    }
    return answer;
}

int main() {
    vector<vector<int> > board = { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
    vector<int> moves = { 1,5,3,5,1,2,1,4 };

    cout << solution(board, moves);
    return 0;
}