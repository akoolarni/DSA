#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int min_PATH(vector <vector<int>>& gd){
    int a = gd.size();
    int b = gd[0].size();


    vector <vector<int>> dp(a, vector<int>(b, 0));


    dp[0][0] = gd[0][0];
    for(int i = 1 ; i < a ; i++){
        dp[i][0] = dp[i - 1][0] + gd[i][0];
    }
    for(int j = 1 ; j < b ; j++){
        dp[0][j] = dp[0][j - 1] + gd[0][j];
    }

    
    for(int i = 1 ; i < a ; i++){
        for(int j = 1 ; j < b ; j++){
            dp[i][j] = gd[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[a - 1][b - 1];
}


int main(){
   
    vector <vector<int>> gd = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int result = min_PATH(gd);

    cout << "Minimum path sum is : " << result << endl;

    return 0;
}

//TIME complexity - O(a * b)
//SPACE complexity - O(a * b) 
//a and b as mentioned in the question 