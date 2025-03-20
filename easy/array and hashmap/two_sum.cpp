#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            int counter = nums.size();
            for (int i = 0; i < counter; i++){
                for(int j = i + 1; j < counter; j++){
                    int sum = nums[i] + nums[j];
                    if(sum == target){
                    return {i,j};
                    }
                }
            }
        return {};
    }
};