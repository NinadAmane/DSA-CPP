class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto& str : strs){
            string key = str;
            sort(key.begin(), key.end());

            mp[key].push_back(str);
        }
        
        // int n = mp.size();
        vector<vector<string>> ans;
        auto it = mp.begin();
        while(it != mp.end()){
            ans.push_back(it->second);
            it++;
        }

        return ans;
        
    }
};