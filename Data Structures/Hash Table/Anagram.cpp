#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool anagram(string &word1, string &word2)
{
   unordered_map<char, int> letter;

   if(word1.size() != word2.size())
   {
      return false;
   }

   for(char c : word1)
   {
      letter[c]++;
   }

   for(auto &c : word2)
   {
      if(letter.find(c) == letter.end() || letter[c] <= 0)
      {
        return false;
      }
      else
      {
        letter[c]--;
      }
   }
}

int main()
{
   string word1 = "balm";
   string word2 = "lamb";

   anagram(word1, word2);

}