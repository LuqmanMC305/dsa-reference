#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void access(const unordered_map<string, int> &myMap)
{
    for(const auto &i : myMap)
    {
        cout << "Key: " << i.first << ", Value: " << i.second << endl; 
    }
}

void append(unordered_map<string, int> &myMap)
{
    myMap["Guava"] = 10;
    myMap.insert({"Peach", 6});
}

void deleteElement(unordered_map<string, int> &myMap)
{
    myMap.erase("Apple");
}

void findElement(unordered_map<string, int> &myMap)
{
    string toFind = "Banana";
    auto iterator = myMap.find(toFind);

    if(iterator != myMap.end())
    {
        cout << "Found & its value is " << iterator->second << endl;
    }
    else
    {
        cout << "Not found." << endl;
    }
}

int main()
{
    unordered_map<string, int> myMap;

    myMap = {
        {"Apple", 5},
        {"Banana", 7},
        {"Cherry", 3},
        {"Pineapple", 4},
        {"Papaya", 2}
    };
    
    append(myMap);
    //access(myMap);
    //deleteElement(myMap);

    cout << endl;
    findElement(myMap);

    //Size of hash map

    cout << "The size of hash map is: " << myMap.size() << endl;
    

    return 0;
}