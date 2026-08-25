class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = k;
        unordered_set<int> st(nums.begin(), nums.end());
        while(st.count(ans)){
            ans +=k;
        }
        return ans;
    }
};