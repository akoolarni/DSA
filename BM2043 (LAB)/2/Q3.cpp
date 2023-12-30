#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct ListNode {
    char val;
    ListNode* next;
    ListNode(char x) : val(x), next(nullptr) {}   //list declaration 
};

ListNode* middle(ListNode* head) {
    ListNode* a = head;
    ListNode* b = head;
    while (b != nullptr && b->next != nullptr) {
        a = a->next;
        b = b->next->next;
    }
    return a;
}

ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    ListNode* temp = head;
    int n = 0;
    while (temp != nullptr) {
        temp = temp->next;
        n++;
    }

    temp = head;
    ListNode* head_mid = middle(temp);
    ListNode* head_rev = reverse(head_mid);

    while (head_rev != nullptr) {
        if (head->val != head_rev->val) {
            return false;
        }
        head_rev = head_rev->next;
        head = head->next;
    }

    return true;
}

int main() {
//    ListNode* one = new ListNode(1);
//    ListNode* two = new ListNode(4);
//    ListNode* three = new ListNode(2);
//    ListNode* four = new ListNode(2);
//    ListNode* five = new ListNode(1);


//    ListNode* one = new ListNode(1);
//    ListNode* two = new ListNode(2);
//    ListNode* three = new ListNode(3);
//    ListNode* four = new ListNode(2);
//    ListNode* five = new ListNode(1);

    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(3);
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(0);


    one->next = two;
    two->next = three;
    three->next = four;
   // four->next = five;

    bool result = isPalindrome(one);

    if (result) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }


    while (one != nullptr) {
        ListNode* temp = one;
        one = one->next;
        delete temp;
    }

    return 0;
}

//TIME complexity - O(N)
//SPACE complexity - O(1)