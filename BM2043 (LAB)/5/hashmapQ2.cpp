//The data was not provided in the question. So I tried to experiment the use of hashtables and hashmaps. I hope I do it correctly and properly.

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 1000;  

struct hashfunctioncreation{
    string key;
    int value;
};

struct HashMap{
    vector <hashfunctioncreation> table[TABLE_SIZE];

    
    int hash(const string& key){
        int hash = 0;
        for (char c : key){
            hash = (hash*31+c)%TABLE_SIZE;
        }
        return hash;
    }

    void insert(const string& key, int value){
        int index = hash(key);
        for (auto& kv : table[index]){
            if (kv.key == key){
                
                kv.value = value;
                return;
            }
        }

       
        table[index].push_back({key, value});
    }

    int search(const string& key){
        int index = hash(key);
        for (const auto& kv : table[index]){
            if (kv.key == key){
                return kv.value;
            }
        }

        
        return -1;
    }

    void remove(const string& key){
        int index = hash(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it){
            if(it->key == key){
                bucket.erase(it);
                return;
            }
        }
    }
};

int main(){
    HashMap hashmap;

    hashmap.insert("Arin", 19);
    hashmap.insert("Aryan", 18);

    int ArinAge = hashmap.search("Arin");
    int AryanAge = hashmap.search("Aryan");
    int TanmayAge = hashmap.search("Tanmay");

    cout << "Arin's age: " << ArinAge << endl;   
    cout << "Aryan's age: " << AryanAge << endl; 
    cout << "Tanmay's age: " << TanmayAge << endl;     

    return 0;
}
//The code has time complexity of O(1) for search operation. Also the space complexity depends on TABLE_SIZE. as the size increases , the efficieny increases.
