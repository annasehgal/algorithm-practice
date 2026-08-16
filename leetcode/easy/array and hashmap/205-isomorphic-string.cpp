class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char>dict; //dict1
        unordered_map<char, char> dict2; //dict2
        for(int i =0; i < s.length(); i++){
            if((dict.contains(s[i]) == false || dict[s[i]] == t[i]) 
            && 
            (dict2.contains(t[i])==false || dict2[t[i]] ==s[i])
            ){ // valid cond for if it already maps ?
                dict[s[i]] = t[i]; // a -> b
                dict2[t[i]] = s[i]; // b -> a
            }
            else {
                return false;
            }
        }
        return true;
    }
};
