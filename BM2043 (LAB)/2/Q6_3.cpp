#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void selectionSort(int arr[], int size){
    int i,j,min;
    for(i=0 ; i<size-1 ; i++){
        min = i;
        for(j = i+1 ; j<size ; j++){
            if(arr[min] > arr[j]){
            min = j;
            }
        }
         if(min != i){
            int swap = arr[i];
            arr[i] = arr[min];
            arr[min] = swap;
        }
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

	selectionSort(arr, n);

	cout << "The sorted array after selection sort is : " << endl;
	for(int i=0 ; i<n ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}


//TIME complexity - O(N^2) worst case 
//SPACE complexity - O(1) [in short never > O(N)]