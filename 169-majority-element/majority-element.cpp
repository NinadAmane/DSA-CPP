class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int votes = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(votes == 0){
                candidate = nums[i];
                votes = 1;
            }
            else{
                if(nums[i] == candidate){
                    votes++;
                }
                else{
                    votes--;
                }
            }
        }

        int count = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == candidate){
                count++;
            }
        }

        if(count > n/2){
            return candidate;
        }

        return -1;
    }
};