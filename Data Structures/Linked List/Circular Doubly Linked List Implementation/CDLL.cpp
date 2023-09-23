#include <iostream>
#include <string>
#include "CDLL.h"

using namespace std;

int main(){
    CDLL<int> c1;

    c1.append(1);
    c1.append(2);
    c1.append(5);
    c1.insert(4);

    c1.display();

    cout << endl;
    c1.deleteNode(1);
    c1.display();
}