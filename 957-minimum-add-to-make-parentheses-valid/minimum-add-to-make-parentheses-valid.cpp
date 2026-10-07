class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else if(!st.empty() && s[i] == ')'){
                ans+=2;
                st.pop();
            }
        }

        return n - ans;
    }
};