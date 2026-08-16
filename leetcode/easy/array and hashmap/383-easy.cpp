class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
         unordered_map<char, int> dict;
        for(int i = 0; i < magazine.length(); i++){
            dict[magazine[i]] = dict[magazine[i]] +1;
        }
        for(int j=0; j< ransomNote.length(); j++){ // loop ransomName
            if(dict[ransomNote[j]] > 0){
                dict[ransomNote[j]]--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
