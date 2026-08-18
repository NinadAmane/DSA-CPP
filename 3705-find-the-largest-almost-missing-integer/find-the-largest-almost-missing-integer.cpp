class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n= nums.size();

        if(k==1){
            unordered_map<int,int> freq;
            for(int i=0;i<n;i++){
                freq[nums[i]]++;
            }
            int maxi = INT_MIN;
            for(auto& it: freq){
                if(it.first > maxi && it.second == 1){
                    maxi = it.first;
                }
            }
            return maxi  == INT_MIN ? -1 : maxi;
            
        }
        else if(k==n){
            return *max_element(begin(nums), end(nums));
        }
        else{
            unordered_map<int,int> mp;
            int first = nums[0];
            int last = nums[n-1];
            for(int i=0;i<n;i++){
                mp[nums[i]]++;
            }

            if(mp[first] == 1 && mp[last] == 1){
                return first > last ? first : last;
            }
            else if(mp[first] > 1 && mp[last] == 1){
                return last;
            }
            else if(mp[first] == 1 && mp[last] > 1){
                return first;
            }
        }

        return -1;
    }
};