class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int r=1;
        int prefixsum = nums[l];

        while(r<n){
            if(nums[r] == nums[r-1] + 1){
                prefixsum += nums[r];
                cout << prefixsum << endl;
            }
            else{
                break;
            }
            r++;
        }

        // int maxi = *max_element(begin(nums), end(nums));
        while(find(nums.begin(), nums.end(), prefixsum) != nums.end()){
            prefixsum++;
            
        }

        return prefixsum;
    }
};