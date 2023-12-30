#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& matrix, int i, int j){
    int m = matrix.size();
    int n = matrix[0].size();

    if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] == '0'){
        return;
    }

    matrix[i][j] = '0';  
    
    dfs(matrix, i - 1, j);
    dfs(matrix, i + 1, j);
    dfs(matrix, i, j - 1);
    dfs(matrix, i, j + 1);
}

int number_of_islands(vector<vector<char>> & matrix){
    int count = 0;
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == '1') {
                ++count;
                dfs(matrix, i, j);
            }
        }
    }

    return count;
}

int main(){
    
    vector<vector<char>> matrix1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

//sample test case
//    vector<vector<char>> matrix2 = {
//        {'1', '1', '1', '1', '0'},
//        {'1', '1', '0', '0', '0'},
//        {'1', '1', '0', '1', '0'},
//        {'0', '0', '1', '1', '1'},
//        {'0', '0', '0', '0', '0'},
//        {'0', '0', '0', '1', '0'},
//        {'0', '0', '0', '1', '0'},
//        {'0', '0', '0', '1', '0'},
//        {'0', '0', '0', '1', '1'},
//        {'0', '0', '0', '1', '1'},
//        {'0', '0', '0', '1', '1'},
//        {'0', '0', '1', '1', '1'},
//        {'0', '0', '0', '1', '1'},
//        {'0', '0', '0', '1', '1'}
//    };
//


    int result1 = number_of_islands(matrix1);
//    int result2 = number_of_islands(matrix2);

    cout << "Number of islands: " << result1 << endl;
//    cout << "Number of islands: " << result2 << endl;

    return 0;
}


//TIME complexity - O(m x n)
//SPACE complexity - O(m x n) worst case {otherwise O(1)}