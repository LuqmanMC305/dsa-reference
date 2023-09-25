#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, string> map;
    
    //Insert key-value pairs

    map[0] = "Zero";
    map[1] = "One";
    map[2] = "Two";
    map[3] = "Three";

    //Display value of the key
    cout << map[0] << endl;

    //Modify the value of the key
    map[0] = "zero";

    //Search the value given the key
    int value = 1;
    if(map.find(value) != map.end())
    {
        cout << value << " found!" << endl;
    }
    else
    {
        cout << value << " not found!" << endl;
    }

    //Delete key-value pair given key
    map.erase(0);

    //Size of hash table
    cout << "Size: " << map.size() << endl;

    //Loop through each elements of map
    for(const auto &element : map)
    {
        cout << element.first << " " << element.second << endl;
    }


    return 0;
}