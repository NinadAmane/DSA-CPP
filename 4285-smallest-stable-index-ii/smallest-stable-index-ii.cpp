class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixmax(n);
        vector<int> suffixmin(n);
        int maxi=nums[0];
        prefixmax[0] = nums[0];
        for(int i=1;i<n;i++){
            if(maxi < nums[i]){
                prefixmax[i] = nums[i];
                maxi = nums[i];
            }
            else{
                prefixmax[i] = maxi;
            }
        }

        int mini=nums[n-1];
        suffixmin[n-1] = mini;
        for(int i=n-2;i>=0;i--){
            suffixmin[i] = min(nums[i], suffixmin[i+1]);
        }


        int ans = -1;
        for(int i=0;i<n;i++){
            int stable = prefixmax[i] - suffixmin[i];
            // cout << stable << " ";
            if(stable <= k){
                ans = i;
                break;
            }
        }

        return ans;
    }
};