#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
    
    unordered_map<int, int> mp;

    mp[1] = 10;                   // insert/update
    mp[1]++;                      // increment count

    cout << mp[1] << endl;

    if (mp.find(1) != mp.end()) { }// exists
    

    int value = mp[1];            // access

    mp.erase(1);                  // delete

    for (auto& [k, v] : mp) {}     // iterate
    

    mp.size();                    // size
    mp.empty();                   // empty?
    mp.clear();                   // remove all


    /* FREQUENCY COUNT

    unordered_map<int, int> freq;

    for (int x : nums) {
        freq[x]++;
    }

    */

    return 0;
}

