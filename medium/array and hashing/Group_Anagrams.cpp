#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            int counter = strs.size();
            vector<vector<string>> results; // vector<string> is one list and vector<vector<string>> is a list of lists
            vector<bool> checker(counter, false); // setting everything as false
    
            for (int i = 0; i < counter; i++){
                if (checker[i]){continue;} // already grouped then skip it
                vector<string> tempGroup; // temporary group of list one
                tempGroup.push_back(strs[i]); // pushing all the words one by one
                for(int j = i + 1; j < counter; j++){
                    if(!checker[j] && isValid(strs[i], strs[j])) {
                        tempGroup.push_back(strs[j]); // adding next work in ths list
                        checker[j] = true; // word is grouped
                    }
                }
                results.push_back(tempGroup); // pushing all the lists into another lists of lists
                tempGroup.clear();
            }
            return results;
        }
    
        bool isValid(string a, string b){
            if(a.size() == b.size()){
                sort(a.begin(), a.end());
                sort(b.begin(), b.end());
            }
            return a == b;
        }
    };
    
    