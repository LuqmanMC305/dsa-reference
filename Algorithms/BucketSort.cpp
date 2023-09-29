#include <iostream>

using namespace std;

void bucketSort(int arrNum[], int count[], int arrNumSize, int countSize)
{
    // n = Elements of arrNum
    for(int n = 0; n < arrNumSize; n++)
    {
        int num = arrNum[n];
        count[num]++; //Increment the frequency of each element
    }

    //Reconstructing the sorted array

    int i = 0;

    for(int n = 0; n < countSize; n++)
    {
        for(int j = 0; j < count[n]; j++)
        {
            arrNum[i] = n;
            i++;
        }
    }


}

int main()
{
    int arrNum[] = {2,1,2,0,0,2};
    int count[] = {0,0,0};

    int arrNumSize = sizeof(arrNum)/sizeof(int);
    int countSize = sizeof(count)/sizeof(int);

    bucketSort(arrNum, count, arrNumSize, countSize);

    for(int k = 0; k < arrNumSize; k++)
    {
        cout << arrNum[k] << " ";
    }
    
    return 0;
}