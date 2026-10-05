class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int ans = 0;
        st.push(0);
        for(char c : s){
            if(c == '('){
                st.push(0);
            }
            else if(!st.empty()){
                int prev = st.top();
                st.pop();

                ans = prev == 0 ? 1 : 2 * prev;
                st.top() += ans;
            }
        }
        return st.top();
    }
};