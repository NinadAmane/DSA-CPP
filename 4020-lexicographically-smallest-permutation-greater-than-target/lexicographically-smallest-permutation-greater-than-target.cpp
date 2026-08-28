class Solution {
public:
    string result = "";
    bool solve(string curr, vector<int>& count, string target, bool greater, int i){
        if(i == target.size()){
            if(greater){
                result = curr;
                return true;
            }
            return false;
        }


        for(char ch = 'a'; ch<= 'z'; ch++){
            if(count[ch-'a'] == 0)continue;

            if(greater == false && ch < target[i]){
                continue;
            }

            curr.push_back(ch);
            count[ch-'a']--;

            bool isgreater = greater || ch > target[i];

            if(solve(curr, count, target, isgreater, i+1)){
                return true;
            }

            curr.pop_back();
            count[ch-'a']++;
        }

        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26,0);
        int n = s.size();
        for(int i=0;i<n;i++){
            count[s[i] - 'a']++;
        }


        string curr = "";

        solve(curr, count,target, false, 0);

        return result;
        
    }
};