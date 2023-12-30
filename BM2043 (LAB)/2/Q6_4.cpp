#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
   
    int size1 = mid - left + 1;
    int size2 = right - mid;

    
    int temp1[size1];
    int temp2[size2];

    
    for (int i = 0; i < size1; i++) {
        temp1[i] = arr[left + i];
    }
    for (int i = 0; i < size2; i++) {
        temp2[i] = arr[mid + 1 + i];
    }


    int i = 0; 
    int j = 0; 
    int k = left; 

    while (i < size1 && j < size2) {
        if (temp1[i] <= temp2[j]) {
            arr[k] = temp1[i];
            i++;
        } else {
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = temp1[i];
        i++;
        k++;
    }

    while (j < size2) {
        arr[k] = temp2[j];
        j++;
        k++;
    }
}






void mergeSort(int arr[], int left, int right) {
    if (left < right) {
     
        int mid = left + (right - left) / 2;

       
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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

	mergeSort(arr, 0, n-1);

	cout << "The sorted array after merge sort is : " << endl;
	for(int i=0 ; i<n ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}


//TIME complexity - O(NlogN)
//SPACE complexity - O(N)