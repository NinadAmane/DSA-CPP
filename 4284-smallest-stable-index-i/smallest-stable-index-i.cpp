class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            cout << i << " ";
            maxi = *max_element(nums.begin(), nums.begin() + i + 1);
            
            
            mini = *min_element(nums.begin() + i, nums.end());

            int stable = maxi - mini;
             
            if(stable <= k){
                return i;
            }
        }

        return -1;
        
    }
};