class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int needclosing = 0;
        int ans = 0;
        for(char c : s){
            if(c == '('){
                if(needclosing % 2 == 1){
                    needclosing--;
                    ans++;
                }
                needclosing += 2;
            }
            else{
                needclosing--;
                if(needclosing < 0){
                    ans++;
                    needclosing = 1;
                }
            }
        }
        return ans+needclosing;
    }
};