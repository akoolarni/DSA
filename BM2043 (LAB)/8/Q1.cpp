#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int coin_CHNGE(int amt, const vector<int>& cs){
   
    vector<int> dp(amt + 1, 0);
    
    
    dp[0] = 1;

   
    for(int coin : cs){
        for(int i = coin ; i <= amt ; i++){
            
            
            dp[i] = dp[i] + dp[i - coin];
        }
    }

 
    return dp[amt];
}

int main(){
    
    vector <int> cs = {1, 2, 5};
    int amt = 5;

    int result = coin_CHNGE(amt, cs);

    cout << "Number of combinations of the coins  will be : " << result << endl;

    return 0;
}

//TIME complexity - O(cs * amt)
//SPACE complexity - O(amt) 
//cs and amt as mentioned above