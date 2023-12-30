#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node *next;
};

struct MinHeap{
    vector <Node *> heap;

    void heapify(int i, int k){
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < k && heap[left] -> data < heap[smallest] -> data){
            smallest = left;
        }

        if(right < k && heap[right] -> data < heap[smallest] -> data){
            smallest = right;
        }

        if(smallest != i){
            swap(heap[i], heap[smallest]);
            heapify(smallest, k);
        }
    }

    void create_heap(Node *arr[], int k){
        for(int i = k/2 - 1 ; i >= 0 ; i--){
            heapify(i, k);
        }
    }

    Node *Min(){
        Node *minNode = heap[0];
        heap[0] = heap[0] -> next;
        if (heap[0] == NULL){
            heap[0] = heap.back();
            heap.pop_back();
        }
        heapify(0, heap.size());
        return minNode;
    }

    bool isEmpty(){
        return heap.empty();
    }
};

Node *mergeKSortedLists(Node *lists[], int k){
    MinHeap minHeap;
    minHeap.heap.reserve(k);

    for(int i = 0 ; i < k ; i++){
        if(lists[i] != NULL){
            minHeap.heap.push_back(lists[i]);
        }
    }

    minHeap.create_heap(lists, k);

    Node dummy;
    Node *tail = &dummy;

    while(!minHeap.isEmpty()){
        Node *minNode = minHeap.Min();
        tail -> next = minNode;
        tail = tail -> next;
    }

    return dummy.next;
}

void printList(Node *head){
    while(head != NULL){
        cout << head -> data;
        if(head -> next != NULL){
            cout << " -> ";
        }
        head = head -> next;
    }
    cout << endl;
}

int main(){
    Node *arr[3];
    arr[0] = new Node{1};
    arr[0] -> next = new Node{4};
    arr[0] -> next -> next = new Node{5};

    arr[1] = new Node{1};
    arr[1] -> next = new Node{3};
    arr[1] -> next -> next = new Node{4};

    arr[2] = new Node{2};
    arr[2] -> next = new Node{6};

    int k = 3;

    Node *merged = mergeKSortedLists(arr, k);

    cout << "The sorted list after merging " << k << " lists is: ";
    printList(merged);

    return 0;
}

//TIME complexity - O(Nlogk){including the heap time complexity}
//SPACE complexity - O(k){k is number of linked lists}
