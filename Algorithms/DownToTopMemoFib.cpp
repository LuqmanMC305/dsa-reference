#include <iostream>
#include <vector>

using namespace std;

int fib(int n)
{
    if(n < 2)
    {
        return n;
    }

    vector<int> memo = {0,1};

    for(int i = 2; i <=n; i++)
    {
        int temp = memo[1];
        memo[1] = memo[0] + memo[1];
        memo[0] = temp;
    }

    return memo[1];
}

int main()
{
    cout << fib(6);
    return 0;
}