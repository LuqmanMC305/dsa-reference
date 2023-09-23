#include <iostream>
#include <string>

using namespace std;

void ToH(int n, string first, string aux, string end)
{
    if(n == 1)
    {
       cout << "Move disk from " << first << " to " << end << endl;
       return;
    }

    ToH(n-1, first, end, aux); //Move n-1 disks from "first" to "middle" rod (aux) using "end" rod
    cout << "Move disk from " << first << " to " << end << endl;
    ToH(n-1, aux, first, end); //Move n-1 disks from "middle" rod (aux) to "end" rod using "first" rod
}

int main()
{
   string first = "A";
   string aux = "B";
   string end = "C";

   int n = 3;

   ToH(n, first, aux, end);

    return 0;
}