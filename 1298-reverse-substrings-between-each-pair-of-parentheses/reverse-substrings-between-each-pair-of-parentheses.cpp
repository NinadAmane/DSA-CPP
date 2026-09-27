class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n = s.size();
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i] == ')'){
                string temp = "";
                while(st.top()!='('){
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                // reverse(temp.begin(), temp.end());
                for(char c : temp){
                    st.push(c);
                }
            }
            else{
                st.push(s[i]);
            }
        }


        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};