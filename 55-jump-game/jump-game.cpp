// class Solution {
// public:
//     bool f(int ind,  vector<int>& nums, vector<int>& dp){
//         int n = nums.size();
//         if(ind >= n-1){
//             return dp[ind] = true;
//         }

//         if(dp[ind] != -1) return dp[ind];

//         for(int jump = 1; jump <= nums[ind]; jump++){
//             if(f(ind + jump, nums, dp)){
//                 return dp[ind] = true;
//             }
           
//         }

//         return dp[ind] = false;

//     }
//     bool canJump(vector<int>& nums) {
//         int n=nums.size();

//         vector<int> dp(n, -1);
        
//         for(int i=n-2;i>=0;i--){
//             for(int j=0;j<=nums[i] && i+j<n; j++){
//                 if(dp[i + j]){
//                     cout << dp[i] << ',';
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
       
//         return f(0,nums,dp);

//     }
// };


// TABULATION:
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int n=nums.size();
//         vector<bool> dp(n, false);
//         dp[n-1] = true;
//         for(int i=n-2;i>=0;i--){
//             for(int j=0;j<=nums[i] && i+j<n; j++){
//                 if(dp[i + j]){
//                     cout << dp[i] << ',';
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }

//         return dp[0];
//     }
// };



//GREEDY:
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int furthest = nums[0];

        for(int i=0;i<n;i++){
            if(i> furthest) return false;
            furthest = max(furthest, i + nums[i]);
        }

        return true;
    }
};
