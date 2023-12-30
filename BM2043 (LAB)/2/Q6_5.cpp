#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1);    

    for (int j = low; j <= high - 1; j++) {

        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
    
        int pivotIndex = partition(arr, low, high);

    
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}



int main(){

	int n, arr[n];
	
	cout <<  "Enter the size of the array: " << endl ;
	cin >> n;

	cout << "Enter the elements of the array: " << endl;
	for(int i=0 ; i<n; i++){
		cin >> arr[i];
	}

	quickSort(arr, 0, n-1);

	cout << "The sorted array after quick sort is : " << endl;
	for(int i=0 ; i<n ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}


//TIME complexity - O(N^2) worst case  O(NlogN) , best case
//SPACE complexity - O(N)