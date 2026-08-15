class Solution {
public:
    // int longestSubsequence(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n==2 && nums[0] == nums[1]) return 1;

    //     vector<int> pxor(n + 1, 0);
    //     pxor[0] = 0;

    //     for(int i=0;i<n;i++){
    //         pxor[i+1] = nums[i] ^ pxor[i];
    //         cout << pxor[i] <<  " "; 
    //     }
    //     int maxlen = 0;
    //     for(int i=0;i<n;i++){
    //         int len =0;
            
    //         for(int j=i+1;j<n;j++){
    //             if(nums[i] == nums[j]) continue;

                
    //             if(pxor[j+1] ^ pxor[i] !=0){
    //                 len = j - i + 1;
    //                 maxlen = max(maxlen , len);
    //             }

    //         }
    //     }
        
    //     return maxlen;
    // }

    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int resultxor= 0;
        bool allzero = true;

        for(int& x: nums){
            resultxor = resultxor ^ x;
            if(x!=0){
                allzero = false;
            }
        }

        if(allzero) return 0;

        return (resultxor == 0) ? n-1 : n;
    }
};