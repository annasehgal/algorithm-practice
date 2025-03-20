#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            int counter = nums.size();        
            vector<int> missing; // list of numbers in array
            vector<bool> checker(counter + 1, false); // sets everything as false first, counter + 1 because it is from range 1 to n
    
            for (int i = 0; i < counter; i++) {
                if (nums[i] >= 1 && nums[i] <= counter) {  // valid range given
                    checker[nums[i]] = true; // and you mark it is as true which are there in array given
                }
            }
    
            // for the rest which are left, you loop through counter and find the ones in checker which are not true
            for(int i = 1; i <= counter; i++){ // loop through 1 to n
                // if(!checker[i]) {  // negation
                if(checker[i] == false){
                    missing.push_back(i); //adds false value to missing
                }
            }
            return missing;
        }
    };