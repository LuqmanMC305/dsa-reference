#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void twoSum(int arrNum[], int target, int size)
{
   unordered_map<int, int> myMap;
   
  

   for(int i=0; i < size; i++)
   {
      int diff = target - arrNum[i];
      

      if(myMap.find(diff) != myMap.end())
      {
        cout << "Target is found at indices: " << myMap[diff] << " " << i << endl;
        return;
      }
      
      myMap[arrNum[i]] = i;
   }

}


int main()
{
    int arrNum[] = {1,2,3,4,5};
    int target = 6;
    int size = sizeof(arrNum)/ sizeof(arrNum[0]);

    twoSum(arrNum, target, size);
    return 0;
}