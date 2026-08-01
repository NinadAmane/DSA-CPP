class Solution {
public:
    int f(int l, int r, vector<int>&nums,int n){
        if(l==r){
            return nums[l];
        }

        return max(nums[l] - f(l+1,r, nums, n) , nums[r] - f(l,r-1,nums,n));
    }
    bool predictTheWinner(vector<int>& nums) {
        int n= nums.size();
        
        return f(0,n-1,nums,n) >=0;
    }
};