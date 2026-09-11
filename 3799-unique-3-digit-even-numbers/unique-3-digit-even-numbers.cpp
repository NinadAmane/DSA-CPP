class Solution {
public:
    void f(int ind, string temp, vector<int>& digits, unordered_set<int>& ans, vector<bool>& used){
        int n=digits.size();
        if(temp.size() == 3){
            int d = stoi(temp);
            if(d %2 == 0){
                ans.insert(d);
            }
            return;
        }

        for(int i=0;i<n;i++){
            if(used[i]) continue;

            if(temp.empty() && digits[i] == 0) continue;
            used[i] = true;

            temp += to_string(digits[i]);


            f(ind + 1, temp, digits, ans, used);

            temp.pop_back();
            used[i] = false;
        }
    }
    int totalNumbers(vector<int>& digits) {
        int n =digits.size();
        unordered_set<int> ans;
        vector<bool> used(n,false);

        f(0,"", digits,ans, used);

        return ans.size();
    }
};