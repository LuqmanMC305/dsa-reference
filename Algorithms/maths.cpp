#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;

int main() {

    int a = 12;
    int b = 18;

    cout << abs(-5) << '\n';
    cout << pow(2, 5) << '\n';
    cout << sqrt(49) << '\n';

    cout << max(a, b) << '\n';
    cout << min(a, b) << '\n';

    cout << gcd(a, b) << '\n';
    cout << lcm(a, b) << '\n';

    cout << (17 % 5) << '\n';

    return 0;
}