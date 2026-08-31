class Solution {
public:

    int solve(int ind, int sum, vector<vector<pair<int,int>>>& choices, vector<int>& nums, vector<vector<int>>& dp){

        int n = nums.size();
        if(ind >= n){
            if(sum == 0){
                return dp[ind][sum] = 0;
            }
            return dp[ind][sum] = 1e9;
        }

        if(dp[ind][sum] != -1) return dp[ind][sum];

        int take = 1e9;
        for(auto [val, ops] : choices[ind]){
            if(sum - val < 0){
                continue;
            }
            take = min(take, ops + solve(ind + 1, sum - val, choices, nums,dp));
        }

        int skip = solve(ind + 1, sum, choices, nums,dp);

        return dp[ind][sum] = min(skip, take);

    }
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();  
        vector<vector<pair<int,int>>> pairs(n);
        vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));




        for(int i=0;i<n;i++){
            int ops = 0;
            int x = nums[i];
            while(x <= sum){
                pairs[i].push_back({x,ops});
                x*=2;
                ops++;
            }
            x = nums[i];
            ops =0;
            while(x > 0){
                pairs[i].push_back({x,ops});
                x/=2;
                ops++;
            }
        }

        // for(auto x: pairs){
        //     for(auto y : x){
        //         cout << y.first <<  "->" << y.second << " ";
        //     }
        //     cout << endl;
        // }

        return solve(0,sum,pairs, nums,dp) == 1e9 ? -1 : solve(0,sum,pairs, nums,dp);
    }
};