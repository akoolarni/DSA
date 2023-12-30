#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void insertionSort(int arr[], int size){
	int i,j;
	int count=arr[i];

	for(i=0 ; i<size ; i++){
		count = arr[i];
		

		for(j=i-1 ; j>=0 && arr[j]>count ; j--){
			arr[j+1] = arr[j];
			
		
		}

		arr[j+1] = count;
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

	insertionSort(arr, n);

	cout << "The sorted array after insertion sort is : " << endl;
	for(int i=0 ; i<n ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}


//TIME complexity - O(N^2)
//SPACE complexity - O(N)