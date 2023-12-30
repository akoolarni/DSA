#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

void backtrack_Array(const vector<int> &nums, int start, vector<int> &current, vector<vector<int>> &result){
    result.push_back(current);

    for(int i = start; i < nums.size(); ++i){
        current.push_back(nums[i]);
        backtrack_Array(nums, i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int>> subsets(const vector<int> &nums){
    vector<vector<int>> result;
    vector<int> current;
    backtrack_Array(nums, 0, current, result);
    return result;
}

int main(){
    vector<int> nums = {1, 2, 3};
    //vector<int> nums = {1, 2, 3, 4, 5};
    //vector<int> nums = {11, 22, 24};
    

    vector<vector<int>> result = subsets(nums);

   
    for(const auto& subset : result){
        cout << "[";
        for(const auto &num : subset){
            cout << num << ",";
        }
        cout << "], " << endl;
    }

    return 0;
}


//TIME complexity - O(2^N) 
//SPACE complexity - O(2^N)
//here N is the number of elements in the imput array. This is because everytime recursive calls are doubled.
