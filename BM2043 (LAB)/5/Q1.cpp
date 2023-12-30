#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template <typename T, int n>
struct Heap{
    T Heap[n];
    int size;

    void swap(int i, int j){
        T temp = Heap[i];
        Heap[i] = Heap[j];
        Heap[j] = temp;
    }

    void heapify(int i){
        int largest_element = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size && Heap[left] > Heap[largest_element]){
            largest_element = left;
        }

        else if (right < size && Heap[right] > Heap[largest_element]){
            largest_element = right;
        }

        else if(largest_element != i){
            swap(i, largest_element);
            heapify(largest_element);
        }
        
    }

    void insert(T value){
        if(size == n){
            cout << "Heap is full. " << endl;
            return;
        }

        int i = size;
        Heap[i] = value;
        size++;

        while (i > 0 && Heap[i] > Heap[(i-1)/2]){
            swap(i, (i-1)/2);
            i = (i-1)/2;
        }
    
    }

    T max_element(){
        if(size > 0){
            return Heap[0];
        }
        
        else{
            return -1;
        }
    }

    void delete_element(){
        if(size > 0){

             size--;
            Heap[0] = Heap[size];
           
           
            heapify(0);
        }
    }
};


int main(){

    Heap<int, 10> max_heap;
    max_heap.insert(4);
    max_heap.insert(10);
    max_heap.insert(8);
    max_heap.insert(15);
    cout << "Maximum element is: " << max_heap.max_element() << endl;

    max_heap.delete_element();

    cout << "Element after deletion is: " << max_heap.max_element() << endl;





    return 0;
}

//TIME complexity - O(logn) , for some operations its O(1)
//SPACE complexity - O(n) ~ O(10) in this case which is constant