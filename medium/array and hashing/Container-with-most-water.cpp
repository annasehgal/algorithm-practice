#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int left = 0;
            int right = height.size() - 1;
            int area = 0;
            vector<int> maxarea;
    
            while (left < right) {
                int width = right - left;
                area = min(height[left], height[right]) * width;
                maxarea.push_back(area);
                if (height[left] < height[right]) {
                    left++;
                } else{
                    right--;
                }
            }
    
            int finalarea = *max_element(maxarea.begin(), maxarea.end());
            return finalarea;
        }
    };