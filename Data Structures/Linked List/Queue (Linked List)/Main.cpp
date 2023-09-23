#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main()
{
   Queue<int> q1;

   q1.enqueue(1);
   q1.enqueue(2);
   q1.enqueue(3);

   cout << q1.dequeue() << endl;
   cout << q1.dequeue() << endl;
   cout << q1.dequeue() << endl;
   cout << q1.dequeue() << endl;
}