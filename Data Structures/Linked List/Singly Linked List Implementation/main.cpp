#include <iostream>
#include <string>
#include "header.h"

using namespace std;

int main()
{
   LinkedList<int> l1;

   l1.append(1);
   l1.append(2);
   l1.append(3);
   l1.append(4);
   l1.append(5);

   //l1.addBeginning(6);
   //l1.addBeginning(7);

   //l1.deleteIndex(4);

   l1.addAtIndex(3, 10);

   l1.display();
   l1.displayFast();
   
   return 0;
}