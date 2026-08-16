class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l =0;
        int r = 0;
        while(r<n){
            
            while(r+1<n  && nums[r] == nums[r+1]){
                r++;
            }

            swap(nums[l], nums[r]);
            l++;
            r++;
        }

        return l;
    }
};