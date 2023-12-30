#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


string removeDuplicates(string &s){
    string result = "";
    char prev = '0';
    for(int i =  0 ; i < s.length() ; i++){
        char c = s[i];
        if(c != prev){
            result = result + c;
            prev  = c;

        }
    }

    return result;
}






int main(){

    string s;
    cout << "Enter the string ";
    getline(cin , s);
    s = removeDuplicates(s);
    cout << s << endl;

    return 0;
}



// TIME complexity - O(N)
// SPACE complexity - O(N)


