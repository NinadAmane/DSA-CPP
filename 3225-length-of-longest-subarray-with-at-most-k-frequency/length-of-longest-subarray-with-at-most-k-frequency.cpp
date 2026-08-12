class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0;
        int r=0;
        unordered_map<int,int> mp;
        int maxlen = INT_MIN;
        while(r<n){
            mp[nums[r]]++;

            
            while(mp[nums[r]] > k){
                // if(nums[l] == nums[r]){
                    mp[nums[l]]--;
                    if(mp[nums[l]] == 0){
                        mp.erase(nums[l]);
                    }
                // }
                l++;
            }

            if(mp[nums[r]] <= k){
                maxlen = max(maxlen, r - l + 1);
            }



            r++;
        }

        return maxlen;
    }
};