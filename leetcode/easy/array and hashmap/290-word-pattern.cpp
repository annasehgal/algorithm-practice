class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map <char, string> dict1; //char to str
        unordered_map<string, char>dict2; // str to char
        // since we cant compare char and string we do
        stringstream ss(s);
        string word;
        for(int i=0; i < pattern.length(); i++){
            
            if(!(ss >> word)){ 
                return false;
            }
            if(
                (dict1.count(pattern[i])  && dict1[pattern[i]] != word) ||
                (dict2.count(word)  && dict2[word] != pattern[i])){
                return false;
            }
            else {
                dict1[pattern[i]] = word; // a-> word
                dict2[word] = pattern[i]; // word -> a
            }
        }
        if(ss >> word){ // another word
            return false;
        }
        return true;
    }
};
