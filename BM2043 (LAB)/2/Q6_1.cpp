#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void bubbleSort(int arr[], int size){
	
	int swap;
	for(int i=0;i<size;i++){
		for(int j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=swap;
				continue;
			}
			
		}

		
	
	
	}
	

}






int main(){
	
	int n;
	cout << "Enter the size of the array" << endl;
	cin >> n;

	int arr[n];
	cout << "Enter the elements in the array: " << endl;
	for(int i=0 ; i<n ; i++){
		cin >> arr[i];
	}

	bubbleSort(arr, n);

	cout << "The sorted array after bubbleSort  is: " << endl; 
	for(int i=0 ; i<n ; i++){
		cout << arr[i] << " ";
	}

	cout << endl;
	return 0;

}

//TIME complexity - O(N^2)
//SPACE complexity - O(N)