#include <iostream>
#include <unordered_map>

using namespace std;

int fib(int n, unordered_map<int, int> &memo)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    
    //If n is not memoised
    if(memo.find(n) == memo.end())
    {
      //Recursively calculate fib then store in cache
      memo[n] = fib(n-1, memo) + fib(n-2, memo); 
    }

    return memo[n];
}

int main()
{
    unordered_map<int, int> memo;

    cout << fib(3, memo);
    return 0;
}