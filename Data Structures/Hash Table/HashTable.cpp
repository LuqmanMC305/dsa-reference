#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() 
{   
     map<char, string> map = 
     {
        {'A', "Hello"}, 
        {'B', "How"}, 
        {'C', "Are"}, 
        {'D', "You?"}
     };

     

     map['A'] = "Hi";

     for(const auto &pair : map)
     {
       cout << "Key: " << pair.first << " Value: " << pair.second << endl;
     }
     
     map.erase('A'); //Erase the key-value pair
    return 0;
}

