#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> count(vector<string> words)
{
    unordered_map<string, int> freq;

    for(const auto &i : words)
    {
       if(freq.find(i) != freq.end())
       {
           freq[i]++;
       }
       else
       {
        freq[i] = 1;
       }
    }

    return freq;
}

int main()
{
    vector<string> words = {"apple", "banana", "grape", "apple"};

    unordered_map<string, int> wordFrequency = count(words);

    for(const auto &i : wordFrequency)
    {
        cout << "Word: " << i.first << ", Frequency: " << i.second << endl;
    }


}