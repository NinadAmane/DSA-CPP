class Solution {
public:
    int f(int ind, vector<int>& nums,vector<int>& dp){
        int n = nums.size();
        if(ind >= n){
            return dp[ind] = 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int score = INT_MIN;
        score = max(score, nums[ind] - f(ind + 1,nums,dp));
        if(ind+1 <n) score = max(score, nums[ind] + nums[ind + 1] - f(ind+2, nums,dp));
        if(ind+1 <n && ind+2 <n)score = max(score, nums[ind] + nums[ind + 1] + nums[ind + 2] - f(ind + 3, nums,dp));
        
        return dp[ind] = score;
        
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();

        vector<int> dp(n+1,-1);
        int score = f(0,stoneValue,dp);

        if(score < 0) return "Bob";
        else if( score >0) return "Alice";
        else{
            return "Tie";
        }

        return "";
    }   
};