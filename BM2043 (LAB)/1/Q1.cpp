#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
struct stack{

	int *arr;
	int top;
	int size; 

	stack(int s){
		size = s;
		arr = new int[size];
		top = -1;
	}

	bool isEmpty(){
		return (top == -1);
	}

	bool isFull(){
		return (top == (size-1));
	}

	void push(int n){
		if(isFull()){
			cout << "The stack is FULL! " << endl;
		}

		else{
			cout << "Push the element " << n << "into the stack. " << endl;
			top++;
			arr[top] = n;
		}
	}

	void pop(){
		if(isEmpty()){
			cout << "The stack is EMPTY! " << endl;
		}
		else{
			cout << "The popped element is " << arr[top] << endl;
			top = top - 1;
		}
	}

	void print(){
		if(isEmpty()){
			cout << "The stack has no elements (EMPTY!)" << endl;
		}
		else{
			cout << "The elements of the stack are : " << " " << endl;
			for(int i = top ; i >= 0 ; i--){
				cout << arr[i] << endl;
			}
		}
	}

};






int main(){

	int size;
	cout << "Enter the size of the array:" << endl;
	cin >> size;
	
	stack s(size);



	s.push(23);
	s.push(50);
	s.push(21);
	s.push(211);
	s.push(7666);


	s.print();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();

	s.print();

	
	return 0;
}
