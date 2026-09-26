class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        unordered_map<string,string> mp;
        for(auto x : knowledge){
            string key = x[0];
            string val = x[1];
            mp[key] = val;
        }

        // vector<string> ans = keys(s);
        // for(auto x : ans){
        //     cout << x << endl;
        // }
        string ans = "";
        for(int i=0;i<n;i++){
            string var = "";
            if(s[i] == '('){
                i++;
                while(s[i] != ')'){
                    var += s[i];
                    i++;
                }
                cout << var << endl;
                if(mp.count(var)){

                    ans += mp[var];
                }
                else{
                    ans += '?';
                }
            }
            // else if(s[i] == ')'){
            //     // if(mp.count(var)){
            //     // }
            //     // else{
            //         // ans += '?';
            //     // }
            // }
            else{
                ans += s[i];
            }

        }
        return ans;
    }
};