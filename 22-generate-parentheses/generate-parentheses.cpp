class Solution {
public:
    void f(int open, int close, int n, string temp, vector<string>& ans){
        if(temp.length() == 2*n){
            ans.push_back(temp);
            return;
        }
        if(open < n){
            // temp += "(";
            f(open+1,close,n,temp + "(",ans);
            // temp.pop_back();
        }
        if(close < open){
            
            f(open, close + 1,n, temp + ")" ,ans);
            // temp.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(0,0,n,"", ans);
        return ans;
    }
};