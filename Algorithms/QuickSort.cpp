#include <iostream>
#include <string>
#include "time.h"

using namespace std;

void swap(int arrNum[], int index1, int index2);
int partition(int arrNum[], int minIndex, int maxIndex, int pivot);

void quicksort( int arrNum[], int minIndex, int maxIndex)
{
    //If there's only one element when partitioning 
    if(minIndex >= maxIndex)
    {
        return;
    }

    //Randomised pivot selection
    int randomPivot = minIndex + rand() % (maxIndex - minIndex + 1);
    int pivot = arrNum[randomPivot];
    swap(arrNum, randomPivot, maxIndex);

    
    int left = partition(arrNum, minIndex, maxIndex, pivot); // left is original pivot value that has been swapped


    quicksort(arrNum, minIndex, left - 1); //Recursively call the left side of pivot 
    quicksort(arrNum, left + 1, maxIndex);  //Recursively call the right side of pivot
}

int partition(int arrNum[], int minIndex, int maxIndex, int pivot)
{
    int left = minIndex;
    int right = maxIndex;

    while(left < right)
    {
        //If left pointer is larger than pivot or If minIndex == maxIndex, stop the left pointer moving
        while(arrNum[left] <= pivot && left < right)
        {
            left++;
        }

        while(arrNum[right] >= pivot && left < right)
        {
            right--;
        }

        swap(arrNum, left, right);
    }
    
    swap(arrNum, left, maxIndex); // maxIndex = pivot
    return left;
}

void swap(int arrNum[], int index1, int index2)
{
    int temp = arrNum[index1];
    arrNum[index1] = arrNum[index2];
    arrNum[index2] = temp;
}

int main()
{
    srand(time(0));

    const int SIZE = 10;
    int arrNum[SIZE];

    for (int i=0; i<SIZE; i++)
    {
       arrNum[i] = rand() % 11;
    }
    
    quicksort(arrNum, 0, SIZE-1);

/*
    for (int i=0; i<SIZE; i++)
    {
       cout << arrNum[i] << " ";
    }

*/
    return 0;
}