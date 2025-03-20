#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    public:
        bool containsDuplicate(std::vector<int>& nums) {
            std::sort(nums.begin(), nums.end()); 
            int counter = nums.size() - 1; 
            for (int i = 0; i < counter; i++){
                // for (int j = i+1; j < counter;j++){
                //     if(nums[i] == nums[j]){
                //         return true;
                //     }
                if(nums[i] == nums[i + 1]){
                        return true;
                }
            }
        return false;
    }
};