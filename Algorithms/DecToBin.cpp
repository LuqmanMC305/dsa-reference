#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string decToInt(int num)
{
    if (num <= 0) return "";

    return to_string(num % 2) + decToInt(num / 2);
}

int main()
{
    int num = 101;
    string binNum = decToInt(num);

    reverse(binNum.begin(), binNum.end());
    cout << binNum << endl;

    return 0;
}