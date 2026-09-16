class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int n, int k, int i, vector<vector<long>>& dp){
        if(k==0) return 1;
        if(i >= n) return 0;
       
        if(dp[i][k] != -1) return dp[i][k] % mod;
        int skip = solve(n, k, i + 1,dp);
        int take = 0;
        for(int j = i + 1; j<=n-1;j++){
            take = (take + solve(n, k - 1, j,dp) % mod) % mod;
        }

        return dp[i][k] = ((skip%mod + take%mod)) % mod;
    }
    // int numberOfSets(int n, int k) {
    //     vector<vector<long>> dp(n+1, vector<long>(k+1, -1));

    //     return solve(n,k,0,dp) % mod;
    // }



    //BOTOOM UP APPRAOCH
    int numberOfSets(int n, int k) {
        vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));

        // dp[n][k]
        for(int i=0;i<n;i++){
            dp[i][0] = 1; //for every k=0 and i < n the answer would be 1. (base case)
        }

        for(int kk = 1; kk <= k; kk++){
            vector<int> prev(n+1,0);
            for(int x=n-1;x>=0;x--){
                prev[x] = (dp[x][kk-1] + prev[x+1])%mod;
            }
            for(int i=n-1;i>=0;i--){
                long long skip = (dp[i+1][kk])%mod;
                long long take = prev[i+1] % mod;
                dp[i][kk] = (take + skip)%mod;
            }

        }

        return dp[0][k];


    }
};