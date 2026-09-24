// =====================================================================
// Greedy Algorithms — Combined Reference (C++)
// Compile:  g++ -std=c++17 -O2 greedy_cheatsheet.cpp -o greedy
// Run:      ./greedy
// =====================================================================
#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------------------
// 1) Activity Selection (Interval Scheduling)
//    Max number of non-overlapping intervals. Sort by END time.
// ---------------------------------------------------------------------
int maxActivities(vector<pair<int,int>> intervals) {
    sort(intervals.begin(), intervals.end(),
         [](auto& a, auto& b){ return a.second < b.second; });

    int count = 0, lastEnd = INT_MIN;
    for (auto& [start, end] : intervals) {
        if (start >= lastEnd) {
            count++;
            lastEnd = end;
        }
    }
    return count;
}

// ---------------------------------------------------------------------
// 2) Fractional Knapsack
//    Sort by value/weight ratio, descending. Take greedily, fraction last.
// ---------------------------------------------------------------------
double fractionalKnapsack(int capacity, vector<pair<int,int>> items) {
    // items = {value, weight}
    sort(items.begin(), items.end(), [](auto& a, auto& b){
        return (double)a.first / a.second > (double)b.first / b.second;
    });

    double totalValue = 0;
    for (auto& [value, weight] : items) {
        if (capacity >= weight) {
            capacity -= weight;
            totalValue += value;
        } else {
            totalValue += value * ((double)capacity / weight);
            break;
        }
    }
    return totalValue;
}

// ---------------------------------------------------------------------
// 3) Jump Game (Reachability) — LeetCode 55
//    Track farthest index reachable so far.
// ---------------------------------------------------------------------
bool canJump(vector<int>& nums) {
    int farthest = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (i > farthest) return false;
        farthest = max(farthest, i + nums[i]);
    }
    return true;
}

// ---------------------------------------------------------------------
// 4) Gas Station — LeetCode 134
//    If total gas >= total cost, a valid start exists.
// ---------------------------------------------------------------------
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < (int)gas.size(); i++) {
        int diff = gas[i] - cost[i];
        total += diff;
        tank += diff;
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    return total >= 0 ? start : -1;
}

// ---------------------------------------------------------------------
// 5) Huffman-style Merge Cost — LeetCode 1167 / 1962
//    Always merge the two smallest elements (min-heap).
// ---------------------------------------------------------------------
int minMergeCost(vector<int> nums) {
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    int totalCost = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        totalCost += a + b;
        pq.push(a + b);
    }
    return totalCost;
}

// ---------------------------------------------------------------------
// 6) Assign Cookies (Two-Pointer Greedy) — LeetCode 455
//    Sort both arrays; match smallest feasible pairs.
// ---------------------------------------------------------------------
int findContentChildren(vector<int> g, vector<int> s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0;
    while (i < (int)g.size() && j < (int)s.size()) {
        if (s[j] >= g[i]) i++;
        j++;
    }
    return i;
}

// =====================================================================
// Demo driver — runs each application on a sample input
// =====================================================================
int main() {
    cout << fixed << setprecision(2);

    // 1) Activity Selection
    {
        vector<pair<int,int>> intervals = {{1,3},{2,4},{3,5},{0,6},{5,7},{8,9},{5,9}};
        cout << "[1] Activity Selection -> max non-overlapping: "
             << maxActivities(intervals) << " (expected 4)\n";
    }

    // 2) Fractional Knapsack
    {
        vector<pair<int,int>> items = {{60,10},{100,20},{120,30}}; // {value, weight}
        int capacity = 50;
        cout << "[2] Fractional Knapsack -> max value: "
             << fractionalKnapsack(capacity, items) << " (expected 240.00)\n";
    }

    // 3) Jump Game
    {
        vector<int> nums1 = {2,3,1,1,4};
        vector<int> nums2 = {3,2,1,0,4};
        cout << "[3] Jump Game -> [2,3,1,1,4]: " << (canJump(nums1) ? "true" : "false")
             << " (expected true), [3,2,1,0,4]: " << (canJump(nums2) ? "true" : "false")
             << " (expected false)\n";
    }

    // 4) Gas Station
    {
        vector<int> gas  = {1,2,3,4,5};
        vector<int> cost = {3,4,5,1,2};
        cout << "[4] Gas Station -> start index: "
             << canCompleteCircuit(gas, cost) << " (expected 3)\n";
    }

    // 5) Merge Cost (Huffman-style)
    {
        vector<int> nums = {1,2,3,4};
        cout << "[5] Min Merge Cost -> total cost: "
             << minMergeCost(nums) << " (expected 19)\n";
    }

    // 6) Assign Cookies
    {
        vector<int> g = {1,2,3};   // greed factors
        vector<int> s = {1,1};     // cookie sizes
        cout << "[6] Assign Cookies -> content children: "
             << findContentChildren(g, s) << " (expected 1)\n";
    }

    return 0;
}