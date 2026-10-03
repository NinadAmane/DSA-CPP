class Solution {
public:
    bool isval(int n, string s, stack<char>& st){
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(st.empty() || st.top() != '('){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        int ans = 0;
        st.push(-1);
        for(int r=0;r<n;r++){
            if(s[r] == ')'){
                st.pop();
                if(st.empty()){
                    st.push(r);
                }
                else{
                    ans = max(ans,r - st.top());
                }
            }
            else{
                st.push(r);
            }
        }

        return ans;
    }
};