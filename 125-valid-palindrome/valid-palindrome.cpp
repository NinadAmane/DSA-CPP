class Solution {
public:
    bool isPalindrome(string s) {
        string ss = "";
        for(int i=0;i<s.size();i++){
            if(s[i] == ' ' || !isalnum(s[i])){
                continue;
            }
            ss += tolower(s[i]);
        }
            cout << ss << " ";
        int l =0;
        int r = ss.size() - 1;
        while(l<r){
            if(ss[l] != ss[r]){
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};