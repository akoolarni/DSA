#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>

using namespace std;


// queue using a stack 

struct queue{
    stack <int> s1, s2;



    void enqueue(int data){
    s1.push(data);
}

int dequeue(){
    if(s1.empty() && s2.empty()){
        cout << "The queue is EMPTY. " << endl;
        exit(0);
    }


    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }


    int top = s2.top();
    s2.pop();
    return top;
}








};



int main(){

    int keys[5] = {1, 2, 3, 4, 5};
    queue q;


    for(int i = 0 ; i < 5 ; i++){
        q.enqueue(keys[i]);
    }


    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}

// TIME complexity - O(1) & O(N) for the dequeue operation
// SPACE complexity - O(N)