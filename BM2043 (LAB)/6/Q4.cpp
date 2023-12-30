#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

bool is_Palindrome(const string &s, int start, int end){
    while(start < end){
        if(s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void partition_Palindrome(const string &s, int start, vector<string> &current, vector<vector<string>> &result){
    if(start == s.length()){
        result.push_back(current);
        return;
    }

    for(int end = start; end < s.length(); end++){
        if(is_Palindrome(s, start, end)){
            current.push_back(s.substr(start, end - start + 1));
            partition_Palindrome(s, end + 1, current, result);
            current.pop_back(); 
        }
    }
}

vector<vector<string>> partition_Palindrome(const string &s){
    vector<vector<string>> result;
    vector<string> current;
    partition_Palindrome(s, 0, current, result);
    return result;
}

int main(){
    string s = "aab";
    //string s = "aabbb";
    //string s = "abcbcad";
    vector<vector<string>> result = partition_Palindrome(s);

   
    for(const auto &partition : result){
        cout << "[";
        for(const auto &str : partition){
            cout << "\"" << str << "\", ";
        }
        cout << "] " << endl;
    }

    return 0;
}

//TIME complexity - O(N) for is_Palindrome, O(N!) for partition fnction
//SPACE complexity - O(M x 2^N) M is avg. partition length; 2^N is the number of possible partitions
