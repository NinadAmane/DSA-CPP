class Solution {
public:
    string res = "";
    int halflen = 0;
    char mid = ' ';
    bool solve(string& curr, string& target, vector<int>& count, bool greater, int i){
        if(curr.length() == halflen){ 
            string candidate = curr;
            string right = curr;
            reverse(right.begin(), right.end());
            if(mid != ' '){
                candidate += mid;
            }

            candidate += right;

            if(candidate > target){
                res = candidate;
                return true;
            }

            return false;
        }


        for(char ch = 'a'; ch<='z'; ch++){
            if(count[ch - 'a'] == 0) continue;

            else if(greater == false && ch < target[i]){
                continue;
            }

            curr.push_back(ch);
            count[ch-'a']--;

            bool isgreater = greater || ch > target[i];

            if(solve(curr, target, count, isgreater, i+1)){
                return true;
            }

            curr.pop_back();
            count[ch-'a']++;

        }

        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        halflen = n/2;

        vector<int> count (26,0);
        for(int i=0;i<n;i++){
            count[s[i] - 'a']++;
        }
        
        int oddfreq = 0;

        for(int x = 0; x<26; x++){
            if(count[x] %2 != 0){
                oddfreq++;
                mid = x + 'a';
            }

            if(oddfreq > 1) return "";
        }

        for(int i=0; i<26;i++){
            count[i] /= 2;
        }

        string curr = "";

       


        solve(curr, target, count, false, 0);
        
        return res;
    }
};