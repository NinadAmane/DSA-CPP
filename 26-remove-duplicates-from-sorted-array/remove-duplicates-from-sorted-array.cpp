class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k=1;
        for(int i=0;i<n;i++){
            if(nums[i] != nums[k-1]){
                nums[k] = nums[i];
                k++; 
            }
        }
        return k;
    }
};