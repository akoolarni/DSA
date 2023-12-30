#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


struct Node {
    int val;
    Node* next;

    Node(int x) : val(x), next(nullptr) {}   //list declaration
};


void Duplicates(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        Node* count = current;

        while (count->next != nullptr) {
            if (count->next->val == current->val) {
                Node* temp = count->next;
                count->next = count->next->next;
                delete temp;
            } else {
                count = count->next;
            }
        }

        current = current->next;
    }
}


void insertSorted(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr || head->val >= val) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;

        while (current->next != nullptr && current->next->val < val) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}


void sort(Node*& head) {
    Node* sortedList = nullptr;
    Node* current = head;

    while (current != nullptr) {
        insertSorted(sortedList, current->val);
        current = current->next;
    }

    head = sortedList;
}


void print(Node* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(5);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(3);
    //head->next->next->next->next->next = new Node(11);
    //head->next->next->next->next->next->next = new Node(3);
    //head->next->next->next->next->next->next->next = new Node(1);
    cout << "Data of the list enetered by the user: ";
    print(head);


    Duplicates(head);

    cout << "Linked list after removal of duplicates: ";
    print(head);

  
    sort(head);

    cout << "Sorted Linked List is: ";
    print(head);

    
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}



//TIME complexity - O(N^2)
//SPACE complexity - O(N)
