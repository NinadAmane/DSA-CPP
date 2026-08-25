class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        set<int> mp;
        for(int i = 0; i<n; i++){
            mp.insert(nums[i]);
        }
        int maxi = *max_element(nums.begin(), nums.end());
        for(int i=1;i<=maxi+k;i++){
            // cout << k*i << " ";
            if(mp.count(k*i) == 0){
                ans = k*i;
                break;
            }
        }
        cout << ans << " ";
        return ans == maxi ? ans + k : ans ;
    }
};