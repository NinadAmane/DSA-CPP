class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int ans =0;
        int r=n-1;
        while(s[r]==' '){
             r--;
        }
        while(r>=0){
            if(isalpha(s[r])){
                ans++;
                r--;
            }

            else if(s[r] == ' ') break;
        }

        return ans;
    }
};