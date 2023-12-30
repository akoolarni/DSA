#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>


using namespace std;

bool is_Safe(int row, int col, const vector<string> &board, int n){
    
    for(int i = 0; i < row; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

   
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

   
    for(int i = row, j = col; i >= 0 && j < n; i--, j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

void solve_NQueens(int row, int n, vector<string> &board, vector<vector<string>> &solutions){
    if(row == n){
        solutions.push_back(board);
        return;
    }

    for(int col = 0; col < n; col++){
        if(is_Safe(row, col, board, n)){
            board[row][col] = 'Q';
            solve_NQueens(row + 1, n, board, solutions);
            board[row][col] = '.';  
        }
    }
}

    vector<vector<string>> solve_NQueens(int n){
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));

    solve_NQueens(0, n, board, solutions);

    return solutions;
}

int main(){
    int n;
    cout << "Enter the value of n for N-Queens: ";
    cin >> n;

    vector<vector<string>> solutions = solve_NQueens(n);

    cout << "All distinct solutions to the N-Queens puzzle:" << endl;
    for(const auto &solution : solutions){
        for(const string &row : solution){
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}

//TIME complexity - O(N!)
//SPACE complexity - O(N^2)
