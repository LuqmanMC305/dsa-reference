#include <iostream>
#include <time.h>

using namespace std;

void merge(int arrNum[], int leftPart[], int rightPart[], int leftSize, int rightSize);

void mergeSort(int arrNum[], int size)
{

   int inputLength = size;
   if(inputLength <= 1)
   {
     return; //If there's only 1 element in array
   }

   int mid = inputLength / 2;
   int leftPart[mid];
   int rightPart[inputLength - mid]; //Ensure it works when the length is odd
 
   // Filling the left & right side of array
   for(int i = 0; i < mid; i++)
   {
     leftPart[i] = arrNum[i];
   }

   for(int i = mid; i < inputLength; i++)
   {
     rightPart[i - mid] = arrNum[i];
   }
   
   //Continue partitioning until the array size is 1
   mergeSort(leftPart, mid);
   mergeSort(rightPart, inputLength - mid);

   merge(arrNum, leftPart, rightPart, mid, inputLength - mid);

}

void merge(int arrNum[], int leftPart[], int rightPart[], int leftSize, int rightSize)
{
  int leftLength = leftSize;
  int rightLength = rightSize;

  int i = 0, j = 0, k = 0;

  while(i < leftLength && j < rightLength)
  {
    if(leftPart[i] <= rightPart[j])
    {
        arrNum[k] = leftPart[i];
        i++;
    }
    else
    {
       arrNum[k] = rightPart[j];
       j++;
    }

    k++;

  }

  while(i < leftLength)
  {
    arrNum[k] = leftPart[i];
    i++;
    k++;
  }

  while(j < rightLength)
  {
    arrNum[k] = rightPart[j];
    j++;
    k++;
  }

}

int main()
{
    srand(time(0));
    const int SIZE = 20;

    int arrNum[SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        arrNum[i] = (rand() % 100) + 1;
    }

    mergeSort(arrNum, SIZE);

    for(int i = 0; i < SIZE; i++)
    {
        cout << arrNum[i] << " ";
    }
}