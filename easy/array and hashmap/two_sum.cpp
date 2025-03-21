#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            // int counter = nums.size();
            // for (int i = 0; i < counter; i++){
            //     for(int j = i + 1; j < counter; j++){
            //         int sum = nums[i] + nums[j];
            //         if(sum == target){
            //             return {i,j};
            //         }
            //     }
            // }
            // return {};
            
            vector<pair<int, int>> numWithIndex;
            for (int i = 0; i < nums.size(); ++i) {
                numWithIndex.push_back({nums[i], i});
            }
    
            // Sort the array based on the number values
            sort(numWithIndex.begin(), numWithIndex.end());
    
            int left = 0;
            int right = nums.size() - 1;
    
            while (left < right) {
                int sum = numWithIndex[left].first + numWithIndex[right].first;
    
                if (sum == target) {
                // Return the original indices
                    return {numWithIndex[left].second, numWithIndex[right].second};
                } 
                else if (sum < target) {
                    ++left;
                } 
                else {
                    --right;
                }
            }
            return {}; 
        }
    };