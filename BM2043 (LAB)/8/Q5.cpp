#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_SQUARE( vector<vector<char>>& mat){
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int MAX = 0;

    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(mat[i - 1][j - 1] == '1'){
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                MAX = max(MAX, dp[i][j]);
            }
        }
    }

    return MAX * MAX;
}

int main(){
    vector <vector<char>> grid = {{'0', '1'}, {'1', '0'}};
    cout << max_SQUARE(grid) << endl;

    return 0;
}

//TIME complexity - O(m * n)
//SPACE complxity - O(m * n) //m & n as mentioned above in the question 