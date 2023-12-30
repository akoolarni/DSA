#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

void finding_Paths(int i, int j, int m, int n, vector<vector<int>> &matrix, string path, vector<string> &result){
    if(i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] == 0){
        return;
    }

    if(i == m - 1 && j == n - 1){
        result.push_back(path);
        return;
    }

    matrix[i][j] = 0; 

    if(j + 1 < n){
        finding_Paths(i, j + 1, m, n, matrix, path + "R", result);
    }

    if(i + 1 < m){
        finding_Paths(i + 1, j, m, n, matrix, path + "D", result);
    }

    if(j - 1 >= 0){
        finding_Paths(i, j - 1, m, n, matrix, path + "L", result);
    }

    if(i - 1 >= 0){
        finding_Paths(i - 1, j, m, n, matrix, path + "U", result);
    }

    matrix[i][j] = 1; 

}

int main(){
    int m = 4, n = 4;
    vector<vector<int>> matrix = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    vector<string> result;
    finding_Paths(0, 0, m, n, matrix, "", result);

    for(const auto &path : result){
        cout << "\"" << path << "\", ";
        
    }

    cout << endl;

    return 0;
}

//TIME complexity - O(3^(M + N))
//SPACE complexitty - O(M + N)
