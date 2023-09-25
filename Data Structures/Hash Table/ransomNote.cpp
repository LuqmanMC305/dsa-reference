#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string magazine = "aab";
    string ransomNote = "aa";

    unordered_map<char, int> magMap;
    unordered_map<char, int> ransomMap;
   
    //The value of the key assigns to 0 (due to key doesn't exist)
    for(const auto &i : magazine) {magMap[i]++;}
    for(const auto &i : ransomNote) {ransomMap[i]++;}

   


    for(const auto &i :magMap)
    {
       //Compare freq of magMap & freq of ransomMap (key values)
       if(i.second < ransomMap[i.first])
       {
         cout << "a";
       }
    }


   return 0;

}