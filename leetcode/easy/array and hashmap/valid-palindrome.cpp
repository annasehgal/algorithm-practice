#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            int left = 0; // left pointer at start of string
            int right = s.size() - 1; // right pointer at the last element 
     
            while (left < right){ 
                while (left < right && !isalnum(s[left])) { // is alnum is used for alphabets only
                    left++; // if it is not then just move left to skip that character
                }
                while(left < right && !isalnum(s[right])){  // is alnum is used for alphabets only
                    right--; // if it is not then just move right to skip that character
                }
    
                s[left] = tolower(s[left]); // change everything to lowercase
                s[right] = tolower(s[right]); // change everything to lowercase
                if(s[left] != s[right]){ // and compare them and if they are not the same then return false
                    return false; 
                }
                left++; // move left anyway
                right--; //move right anyway
            }
            return true; // at the end condition is true
        }
    };