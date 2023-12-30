#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

vector<int> find_row(int rowind){
    vector<int> row(rowind + 1, 0);
    row[0] = 1;

    for(int i = 1 ; i <= rowind ; i++){
        for(int j = i ; j >= 1 ; j--){
            row[j] = row[j] + row[j - 1];
        }
    }

    return row;
}

int main(){
    int rowind = 4;

    //test cases
    //int rowind = 0;
    //int rowind = 1;
    //int rowind = 2;
    //int rowind = 3;
    //int rowind = 5;
    //int rowind = 6;
    //int rowind = 7;
    //int rowind = 8;
    //int rowind = 9;
    
    vector<int> result = find_row(rowind);

    for(int num : result){
        cout << num << " ";
    }

    cout << endl;

    return 0;
}

//TIME complexity - O(rowind^2)
//SPACE complexity - O(rowind)