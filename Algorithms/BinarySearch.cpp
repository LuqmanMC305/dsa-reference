#include <iostream>
#include <string>

using namespace std;

bool binarySearch(int arr[], int target, int left, int right){

    if (right >= left){ //If the list is empty
        int mid = left + right / 2;
        
        if (arr[mid] == target){
        return true;
        }

        if (target < arr[mid]){
        return binarySearch(arr, target, left, mid-1);
        }

        return binarySearch(arr, target, mid+1, right);

    }

    return false;
     
}

int main(){
    const int SIZE = 5;
    int arrNum[SIZE] = {1,2,3,5,7};
    int target = 2;
    int arrLength = sizeof(arrNum) / sizeof(arrNum[0]);
    int left = 0;
    int right = arrLength-1;

    cout << binarySearch(arrNum, target, left, right);

}