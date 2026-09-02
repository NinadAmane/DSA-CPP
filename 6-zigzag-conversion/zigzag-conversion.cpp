class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.length()){
            return s;
        }
        vector<vector<char>> rows(numRows);
        int idx = 0, d = 1;
        string result = "";
        for(char c : s){
            rows[idx].push_back(c);
            if(idx == 0){
                d = 1;
            }
            else if(idx == numRows - 1){
                d = -1;
            }

            idx += d;
        }
        for(auto& row : rows){
            for(char ch : row){
                result += ch;
            }
        }

        return result;
    }
};