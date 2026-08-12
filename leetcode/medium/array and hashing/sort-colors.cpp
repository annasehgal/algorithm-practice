#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            /// sort(nums.begin(), nums.end()); // this is wrong because of the time complexity issue since this is O(n log n)
    
            // Iterate over the array, maintaining two pointers, one at the "low" index, 0, and one at the "high", nums.length - 1.
            // Everything to the left of low in the array and everything to the right of high in the array will be assumed sorted. As we iterate through the array, we update our pointers, taking account for two cases
    
            int left = 0;
            int right = nums.size() - 1;
            int arr = 0;
    
            while(arr <= right) {
                // If the index in the array is equal to 0, we swap that with our current low index and then increment the low index, since we know that everything to the left of that index is properly sorted.
                if(nums[arr] == 0) {
                    swap(nums[left],nums[arr]);
                    left++;
                    arr++;
                }
                // Else if the index in the array is equal to 2, we swap that with our current high index and decrement the high index, since everything to right of the high index is sorted. Also take care in this case to decrement i since we will want to reconsider the inserted element.
    
    
                else if (nums[arr] == 2){
                    swap(nums[right], nums[arr]);
                    right--;
                }
                //  Also take care in this case to decrement i since we will want to reconsider the inserted element.
                else{
                     // If it's 1, just move the current pointer forward
                    arr++;
                }
            }
        }
    };