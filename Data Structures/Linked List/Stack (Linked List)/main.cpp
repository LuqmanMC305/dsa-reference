#include <iostream>
#include <string>
#include "header.h"

using namespace std;

int main()
{
    Stack s1;
    s1.push(1);
    s1.push(7);
    s1.push(3);

    while(!s1.isEmpty())
    {
        cout << s1.peek() << endl;
        s1.pop();
    }

    return 0;
}