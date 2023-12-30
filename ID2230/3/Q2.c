#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TABLE_SIZE1 1024 
#define TABLE_SIZE2 2048 
#define NUM_STUDENTS 1000

struct Student{
    int aadhar_number;
    char name[50];
};

struct Hash_Table{
    struct Student *table;
    int size;
};

unsigned int hash1(int key, int size){
    return key % size;
}

unsigned int hash2(int key, int size){
    return 7 - (key % 7);
}

void initialize_Hash_Table(struct Hash_Table *ht, int size){
    ht -> size = size;
    ht -> table = (struct Student *)malloc(size *sizeof(struct Student));
    for(int i = 0 ; i < size ; i++){
        ht -> table[i].aadhar_number = -1; 
    }
}

void insert(struct Hash_Table *ht, struct Student student){
    int key = student.aadhar_number;
    unsigned int index = hash1(key, ht -> size);
    unsigned int step = hash2(key, ht -> size);

    while(ht -> table[index].aadhar_number != -1){
        index = (index + step) % ht -> size;
    }
    ht -> table[index] = student;
}

bool search(struct Hash_Table* ht, int key, int *probes){
    unsigned int index = hash1(key, ht -> size);
    unsigned int step = hash2(key, ht -> size);
    int count = 0;

    while(ht -> table[index].aadhar_number != -1 && ht -> table[index].aadhar_number != key){
        index = (index + step) % ht -> size;
        count++;
    }

    *probes = count;
    return(ht -> table[index].aadhar_number == key);
}

bool delete(struct Hash_Table *ht, int key){
    unsigned int index = hash1(key, ht -> size);
    unsigned int step = hash2(key, ht -> size);

    while (ht -> table[index].aadhar_number != -1){
        if(ht -> table[index].aadhar_number == key){
            ht -> table[index].aadhar_number = -1; 
            return true;
        }
        index = (index + step) % ht -> size;
    }

    return false;
}

void printHashTable(struct Hash_Table* ht){
    for(int i = 0 ; i < ht -> size ; i++) {
        printf("ht[%d]: Aadhar Number: %d\n", i, ht -> table[i].aadhar_number);
    }
}

int main(){
    struct Hash_Table ht1, ht2;
    initialize_Hash_Table(&ht1, TABLE_SIZE1);
    initialize_Hash_Table(&ht2, TABLE_SIZE2);
    
    freopen("output2.txt", "w", stdout);

    
    srand(time(NULL));
    for (int i = 0 ; i < NUM_STUDENTS ; i++){
        struct Student student;
        student.aadhar_number = rand() % 10000000 + 1;
        insert(&ht1, student);
        insert(&ht2, student);
    }

    int successful_search_probes = 0;
    int unsuccessful_search_probes = 0;

    for(int i = 0 ; i < 100 ; i++){
        int key = rand() % NUM_STUDENTS + 1;
        int probes = 0;

        if(search(&ht1, key, &probes)){
            successful_search_probes = successful_search_probes + probes;
            delete(&ht1, key);
        } 
        else{
            unsuccessful_search_probes = unsuccessful_search_probes + probes;
        }
    }

    float avg_successful_search_probes = (float)successful_search_probes / 100;
    float avg_unsuccessful_search_probes = (float)unsuccessful_search_probes / 100;

    printf("Average probes for successful searches in ht1: %f\n", avg_successful_search_probes);
    printf("Average probes for unsuccessful searches in ht1: %f\n", avg_unsuccessful_search_probes);

    printHashTable(&ht1);
    printHashTable(&ht2);

    free(ht1.table);
    free(ht2.table);
    
    fclose(stdout);

    return 0;
}

