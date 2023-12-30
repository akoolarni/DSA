#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

struct Solution {
    int missing_positive(vector <int> & nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for(int i = 0; i < n; ++i){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        
        return n + 1;
    }
};

int main(){

    Solution solution;

    vector <int> nums1 = {3, 4, -1, 1};
    vector <int> nums2 = {2,3,5,1,7};
    vector <int> nums3 = {-4,-2,-3,-1,0};
    vector <int> nums4 = {1,20,24,49,99,1000};

    int result1 = solution.missing_positive(nums1);
    int result2 = solution.missing_positive(nums2);
    int result3 = solution.missing_positive(nums3);
    int result4 = solution.missing_positive(nums4);

    cout << "Smallest missing postive integer in the given array is: " << result1 << endl;
    cout << "Smallest missing postive integer in the given array is: " << result2 << endl;
    cout << "Smallest missing postive integer in the given array is: " << result3 << endl;
    cout << "Smallest missing postive integer in the given array is: " << result4 << endl;

    return 0;
}

//as mentioned in the question , the time complexity of the code is O(N) & space complexity will become O(1). 
//using hashmap will take more space complexity due to expansion of data structure 
