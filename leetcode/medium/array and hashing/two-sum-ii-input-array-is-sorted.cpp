#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
    
            int left = 0;
            int right = numbers.size() - 1;
            while (left < right) {
                int totalsum = numbers[left] + numbers[right];
                if (totalsum == target) {
                    return {left + 1, right + 1};
                }
                else if (totalsum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
            return {};
        }
    };