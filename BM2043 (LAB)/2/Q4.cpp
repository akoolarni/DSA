#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* Middle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
   
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(10);

    ListNode* middle = Middle(head);

 
    ListNode* last = head;
    while (last->next != nullptr) {
        last = last->next;
    }

    cout << "First element: " << head->val << endl;
    cout << "Last element: " << last->val << endl;
    cout << "Middle element: " << middle->val << endl;

    // Clean up the memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

//TIME complexity - O(N)
//SPACE complexity - O(1)