#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int addBitwise(int a, int b) {
    while (b != 0) {
        int carry = a & b;      // bits where both are 1 -> carry
        a = a ^ b;               // sum without carry
        b = carry << 1;          // carry shifted into next position
    }
    return a;
}

int binaryToDec(const string& bin) {
    int result = 0;
    for (char c : bin) {
        result = result * 2 + (c - '0');
    }
    return result;
}

string decToBinary(unsigned int n) {
    if (n == 0) return "0";
    std::string result;
    while (n > 0) {
        result += (n % 2) ? '1' : '0';
        n /= 2;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {

    int x = 10; // Binary: 1010

    // Check bit at position i (0-indexed from right)
    int i = 1;
    cout << ((x >> i) & 1) << '\n';   // 1

    // Set bit i to 1
    x |= (1 << 0);
    cout << x << '\n';                // 11 (1011)

    // Clear bit i to 0
    x &= ~(1 << 1);
    cout << x << '\n';                // 9 (1001)

    // Toggle bit i
    x ^= (1 << 2);
    cout << x << '\n';                // 13 (1101)

    // Left shift
    cout << (5 << 1) << '\n';         // 10

    // Right shift
    cout << (10 >> 1) << '\n';        // 5

    // Check odd/even
    if (x & 1)
        cout << "Odd\n";
    else
        cout << "Even\n";

    // Count set bits
    cout << __builtin_popcount(x) << '\n';

    // For long long
    long long y = 123456789LL;
    cout << __builtin_popcountll(y) << '\n';

    cout << addBitwise(100, 200) << '\n';

    cout << binaryToDec("1010") << '\n';
    
    cout << decToBinary(10) << '\n';

    return 0;
}