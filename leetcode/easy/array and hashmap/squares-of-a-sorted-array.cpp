#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            int left = 0;
            int right = nums.size() - 1;
            vector<int> output(nums.size());
            // vector<int>output;
            int index = nums.size() - 1;
    
            while(left <= right) {
                // for(int i = 0; i < nums.size(); i++) {
                //     nums[i] *= nums[i];
                //     output.push_back(nums[i]);
                //     left++;
                //     right--;
                // }
    
                int leftSquare = nums[left] * nums[left];
                int rightSquare = nums[right] * nums[right];
                
                // Compare the squares and insert the larger one at the current index
                if (leftSquare > rightSquare) {
                    output[index--] = leftSquare; // Insert into the output from the back
                    left++;
                } else {
                    output[index--] = rightSquare; // Insert into the output from the back
                    right--;
                }
            }
            // sort(output.begin(), output.end());
            return output;
        }
    };