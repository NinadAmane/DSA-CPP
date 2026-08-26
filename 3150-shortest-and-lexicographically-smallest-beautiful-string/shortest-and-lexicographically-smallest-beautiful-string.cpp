class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        if(count(s.begin(), s.end(), '1') < k) return "";
        vector<string> ans;
        int l =0;
        int r = 0;
        string temp = "";
        int countones = 0;

        while(r < n){
            
            if(s[r] == '1'){
                countones++;
            }

            if(countones > k){
                if(s[l] == '1'){
                    countones--;
                }
                l++;
                
            }

            while(s[l] == '0'){
                l++;
            }
            if(countones <= k){
                temp = s.substr(l, r - l + 1);
            }


            if(count(temp.begin(), temp.end(), '1') == k){
                // cout << temp << " ";
                if(!temp.empty()) ans.push_back(temp);
            }
            r++;
        }
        if(ans.empty()) return "";
        

        string best = ans[0];
        int len = ans[0].size();
        for(int i=0;i<ans.size();i++){
            if(ans[i].size() < len){
                best = ans[i];
                len = ans[i].size();
            }
            else if(ans[i].size() == len){
                if(ans[i] < best){
                    best = ans[i];
                }
            }
        }


        int sz = best.size();
        for(int i = sz - 1; i>=0;i--){
            if(best[i] == '0'){
                best.pop_back();
            }
            else{
                break;
            }
        }
        
        return best;
    }
};