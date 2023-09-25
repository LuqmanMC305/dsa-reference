#include <iostream>
#include <unordered_map>

using namespace std;

bool isDuplicate(int arrNum[], int size)
{
    unordered_map<int, int> map; //<element, frequency>
    int element;

    for(int i = 0; i < size; i++)
    {
      element = arrNum[i];

      if(map.find(element) != map.end())
      {
        //map[arrNum[i]]++;
        return true;
      }
      else
      {
        map[arrNum[i]] = 1;
      }

    }

    return false;


}

int main()
{
    int arrNum[] = {10,20,30,40,50,50};
    int size = sizeof(arrNum)/sizeof(arrNum[0]);
    
    if(isDuplicate(arrNum, size))
    {
        cout << "Contains duplicate" << endl;
    }
    else
    {
        cout << "Doesn't contain duplicate" << endl;
    }

    return 0;
}