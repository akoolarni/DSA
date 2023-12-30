#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>

using namespace std;

// stack using queue

struct Queue{
    queue <int> q;

    void enqueue(int n){
        q.push(n);
    }

    int dequeue(){
        if(isEmpty()){
            cout << "The queue is EMPTY" << endl;
            return -1;
        }

        int front = q.front();
        q.pop();
        return front;
    }

    bool isEmpty(){
        return q.empty();
    }

    int size(){
        return q.size();
    }



};

struct stack{

    Queue q1, q2;

    void push(int n){
        q1.enqueue(n);

        while(!q2.isEmpty()){
            q1.enqueue(q2.dequeue());
        }

        swap(q1, q2);
    }


    int pop(){
        if(isEmpty()){
            cout << "The stack is EMPTY " << endl;
            return -1;

        }
        return q2.dequeue();
    }

    bool isEmpty(){
        return q2.isEmpty();
    }

    int size(){
        return q2.size();
    }

};


int main(){
    stack s;

    s.push(1);
    s.push(3);
    s.push(2);

    cout << "Enter the stack size:" << s.size() << endl;

    cout << "Popped element is " << s.pop() << endl;
    cout << "Popped element is " << s.pop() << endl;

    cout << "Stack size after popping is " << s.size() << endl;

    return 0;

}


// TIME complexity - O(1) & O(N) for pop operation
// SPACE complexity - O(N)