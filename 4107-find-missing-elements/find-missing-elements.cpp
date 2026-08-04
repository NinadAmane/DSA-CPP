class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(begin(nums), end(nums));
        int maxi = *max_element(begin(nums), end(nums));
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=mini;i<maxi;i++){
            if(find(begin(nums),end(nums), i) == nums.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};