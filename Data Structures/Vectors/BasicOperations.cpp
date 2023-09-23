#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<int> v1)
{
    for(int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }

    cout << endl;
    
    //using foreach loop
    for(const auto &num : v1)
    {
        cout << num << " ";
    }
}

void isEmpty(vector<int> v1)
{
    if(v1.empty())
    {
        cout << "Empty." << endl;
    }
    else
    {
        cout << "Not empty." << endl;
    }
}

vector<int> returnMultipleElements()
{
    vector<int> returnedNum;

    returnedNum.push_back(20);
    returnedNum.push_back(30);

    return returnedNum;

}

int main()
{
    vector<int> v1 = {1,2,3,4,5};

    //Append elements to vector
    v1.push_back(6);
    v1.push_back(7);

    //Remove last element
    v1.pop_back();

    //Modify the elements
    v1[1] = 10;

    printVector(v1);
    cout << endl;

    //Determine if it's empty
    isEmpty(v1);

    //Return multiple values using vector
    vector<int> returnedElements = returnMultipleElements();
    cout << returnedElements[0] << " " << returnedElements[1] << endl;




    
  




    return 0;
}