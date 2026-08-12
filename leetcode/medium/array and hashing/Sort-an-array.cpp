// this solution exceeds memory time and worst case is O(n^2) sadly so i need a better way to do it

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return nums;
        }
        else {
            int pivot = nums[n - 1];
            vector<int> Left;
            vector<int> Right;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] <= pivot) {
                    Left.push_back(nums[i]);
                }
                else {
                    Right.push_back(nums[i]);
                }
            }
            vector<int>LPrime = sortArray(Left);
            vector<int>RPrime = sortArray(Right);

            vector<int> Combined = LPrime;
            Combined.push_back(pivot);
            for(int value : RPrime) {
                Combined.push_back(value);
            }
            return Combined;
        }
    }
};