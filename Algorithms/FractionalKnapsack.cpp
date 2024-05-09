#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item
{
    public:
      int val, weight;
      double ratio;
      Item(int val, int weight) : val(val), weight(weight) {ratio = (double)val / (double)weight;}
     
};

//Sort items based on their value-to-weight ratio, descending order
bool compareItems(const Item &a, Item &b) {return a.ratio > b.ratio;}


double fracKnapsack(vector<int> &values, vector<int> &weights, int capacity)
{
   int n = values.size();
   vector<Item> items;

   for(int i = 0; i < n; i++)
      items.push_back(Item(values[i], weights[i]));
   
   sort(items.begin(), items.end(), compareItems);

   double totalVal = 0.0;

   for(const Item& item : items)
   {
      if(capacity == 0)
        break;
      
      // Take the maximum possible amount of the item
      int maxAmount = min(item.weight, capacity);
      totalVal += maxAmount * item.ratio;
      capacity -= maxAmount;
   }

   return totalVal;


}

int main()
{
    vector<int> values = {3, 20, 10, 15, 50};
    vector<int> weights = {2, 3, 2, 5, 6};
    int capacity = 15;

    double maxVal = fracKnapsack(values, weights, capacity);
    cout << "Max Val: " << maxVal << endl;

    return 0;
}