#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int max_SUBARRAY(const vector<int>& nms){
    int a = nms.size();
    int mxs = 0;
    int crntsum = 0;

    for(int i = 0 ; i < a ; i++){
        crntsum = max(0, crntsum + nms[i]);
        mxs = max(mxs, crntsum);
    }

    return mxs;
}

int main(){
    vector <int> array = {1, -2, 5, -3, 4};
    cout << max_SUBARRAY(array) << endl;

    return 0;
}


//TIME complexity - O(n)
//SPACE complexity - O(1)

//in this case n = a