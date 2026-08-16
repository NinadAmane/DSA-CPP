class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(int i=0;i<ransomNote.size();i++){
            mp[ransomNote[i]]++;
        }

        for(char c: magazine){
            mp[c]--;
        }

        for(auto it: mp){
            if(it.second >= 1){
                return false;
            }
        }

        return true;
    }
};