#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void min_heapify(int arr[], int n, int i){
    int smallest_element = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest_element]){
        smallest_element = left;
    }

    if(right < n && arr[right] < arr[smallest_element]){
        smallest_element = right;
    }

    if(smallest_element != i){
        swap(arr[i], arr[smallest_element]);
        min_heapify(arr, n, smallest_element);
    }
}

void max_heapify(int arr[], int n, int i){
    int largest_element = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest_element]){
        largest_element = left;
    }

    if(right < n && arr[right] > arr[largest_element]){
        largest_element = right;
    }

    if(largest_element != i){
        swap(arr[i], arr[largest_element]);
        max_heapify(arr, n, largest_element);
    }
}

void min_heap(int arr[], int n){
    for(int i = n/2-1 ; i >= 0 ; i--){
        min_heapify(arr, n, i);
    }
}

void max_heap(int arr[], int n){
    for(int i = n/2-1 ; i >= 0 ; i--){
        max_heapify(arr, n, i);
    }
}

int kthSmallest(int arr[], int n, int k){
    min_heap(arr, n);
    for(int i = 0 ; i < k-1 ; i++){
        swap(arr[0], arr[n - 1]);
        n--;
        min_heapify(arr, n, 0);
    }
    return arr[0];
}

int kthLargest(int arr[], int n, int k){
    max_heap(arr, n);
    for(int i = 0 ; i < k-1 ; i++){
        swap(arr[0], arr[n - 1]);
        n--;
        max_heapify(arr, n, 0);
    }
    return arr[0];
}

int main() {
    int arr[] = {1, 7, 2, 3, 4, 5, 6, 7, 0, 13, 3};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);

    int kthSmallestElement = kthSmallest(arr, n, k);
    int kthLargestElement = kthLargest(arr, n, k);

    cout << "Kth smallest element in the heap is: " << kthSmallestElement << endl;
    cout << "Kth largest element in the heap is: " << kthLargestElement << endl;

    return 0;
}


//TIME complexity - O(N){heap building} + O(k logN){find kth smallest & largest}
//SPACE complexity - O(N){uses the input array itself}