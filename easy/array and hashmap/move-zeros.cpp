#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            // solving with two pointer approach
            int counter = nums.size();
            int left = 0; // left pointer starts at the start of array
            int right = 0; // right pointer at the start of array 
    
            while(right < counter){ 
                if(nums[right] != 0){ // when the right side is not zero  
                    if(left != right) { //if the left side is not equal to right side
                        swap(nums[left],nums[right]); // we swap them
                    }
                    left++; // else it moves left
                }
                right++; // moves right pointer always moves right when nums[right] == 0, just moves right
            }
        }
    };