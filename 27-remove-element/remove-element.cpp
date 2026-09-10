class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        unordered_map<int,int> freq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] != val){
                freq[nums[i]]++;
                // cout << nums[i] << " ";
            }
        }

        int i=0;
        for(auto& it : freq){
            cout << it.first << "->" <<it.second<<" ";
            while(it.second--){
                nums[i] = it.first;
                i++;
            }
        }
        
        return i;
    }
};