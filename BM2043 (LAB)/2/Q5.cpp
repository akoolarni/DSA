#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {} // list declaration
};


Node* reverse(Node* head) {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
     
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

 
        current = current->prev; 
    }


    if (temp != nullptr) {
        head = temp->prev;
    }

    return head;
}


void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    
    Node* head = new Node(2);
    Node* second = new Node(-3);
    Node* third = new Node(0);
    Node* fourth = new Node(2);
    Node* fifth = new Node(2);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    cout << "Data of the input list is: ";
    print(head);

   
    head = reverse(head);

    cout << "The reveresed linked list is: ";
    print(head);


    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}


//TIME complexity - O(N)
//SPACE complexity - O(1)