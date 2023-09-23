#include <iostream>
#include <string>

using namespace std;

void selectionSort(int array[], int size, int minIndex)
{
    for (int i = 0; i<size; i++)
    {
      minIndex = i;

      for(int j = i+1; j<size; j++)
      {
        if (array[j] < array[minIndex])
        {
            minIndex = j;
        }

      }
      int temp = array[i];
      array[i] = array[minIndex];
      array[minIndex] = temp;
    }
}

int main()
{
    int array[] = {64,25,12,22,11};
    int size = sizeof(array) / sizeof(array[0]);
    int minIndex;

    selectionSort(array, size, minIndex);

    for(int i=0; i<size; i++)
    {
        cout << array[i] << " ";
    }
}