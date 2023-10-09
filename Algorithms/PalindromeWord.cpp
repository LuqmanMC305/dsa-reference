#include <iostream>

using namespace std;

bool check(string word, int left, int right)
{
    if(left >= right)
    {
        return true;
    }

    if(word[left]!= word[right])
    {
        return false;
    }

    return check(word, left + 1, right - 1);
}

int main()
{
   string word = "racecar";
   int left = 0, right = word.size() - 1;

   if(check(word, left, right))
   {
     cout << "It is a palindrome." << endl;
   }
   else
   {
     cout << "Not a palindrome." << endl;
   }

   return 0;
}