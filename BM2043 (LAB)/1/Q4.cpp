#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// defined a function
// the given function provides the code to actually check the next greater element in the input array and check the necessary conditions, as per the question
// the function takes in the account two parameters : the input array and the size of the array to account for further part of the algorithm
void nextGreaterCheck(int arr[], int n){
    // declaring a variable, that holds the value of next greater element, whatever it is
    int nge;                                
    // code for the logic inside nested loop 
    // outer loop takes an element of the array
    // inner loop then compares the element chosen with the other elements, one-by-one
    // once the desired greater element is obtained, the loop breaks and the iterations start again for the next element
    // once the loops iterate over the array, the print statement will print the element and its next greater element
    for(int i = 0 ; i < n ; i++){
        nge = -1;
        for(int j = (i+1) ; j < n ; j++){
            if(arr[i] < arr[j]){
                nge = arr[j];
                break;
            }
        }

        cout <<"The next greater element for the array " << arr[i] << " is " << nge << endl;
    }
}

// the function is called here
int main(){
    // declaring the variable for the array size
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;

    // declaring the array for taking user input
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for(int x = 0 ; x < n ; x++){
        cin >> arr[x];
    }

    // passing the function with the required arguements
    nextGreaterCheck(arr, n);

    return 0;

}

// TIME complexity - O(N^2) (big-Oh(N square))
// SPACE complexity - O(N) (big-Oh(N))