#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int longest_PALI(const string& s){
    int a = s.length();
    vector <vector<bool>> pali(a, vector<bool>(a, false));

    int maxl = 1;

    for(int i = 0 ; i < a ; i++){
        pali[i][i] = true;
    }

    for(int l = 2; l <= a; l++){
        for(int i = 0 ; i <= a - l ; i++){
            int j = i + l - 1;

            if(l == 2 && s[i] == s[j]){
                pali[i][j] = true;
                maxl = max(maxl, l);
            } 
            
            else if(s[i] == s[j] && pali[i + 1] [j - 1]){
                pali[i][j] = true;
                maxl = max(maxl, l);
            }
        }
    }

    return maxl;

    }

int main(){

    //string s = 'abcddcba';
    //string s = 'abcdefgh';
    //string s = 'd';
    //string s = 'cddc';
    string s = "babad";
    cout << longest_PALI(s) << endl;

    return 0;
}


//TIME complexity - O(a * a)
//SPACE complexity - O(a * a)