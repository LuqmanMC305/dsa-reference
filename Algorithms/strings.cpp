#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s = "hello";

    cout << s.size() << '\n';

    cout << s[0] << '\n';

    s += " world";

    cout << s.substr(0, 5) << '\n';

    cout << s.find("world") << '\n';

    reverse(s.begin(), s.end());

    cout << s << '\n';

    sort(s.begin(), s.end());

    cout << s << '\n';

    return 0;
}