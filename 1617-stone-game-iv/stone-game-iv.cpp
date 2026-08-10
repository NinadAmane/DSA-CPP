class Solution {
public:
    bool isperfect(int x){
        int root = sqrt(x);
        return root*root == x;
    }
    // bool solve(int ind, int n, vetor<bool>& dp){// can alice win if the game starts with n.
    //     if(ind == 0){
    //         if(isperfect(ind)){
    //             return dp[ind] = true;
    //         }
    //         return dp[ind] = false;
    //     }

    //     if(dp[ind] != -1) return dp[ind];

        

    // } 

    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);

        dp[0] = false;
        dp[1] = true;
        for(int i=1;i<=n;i++){
            for(int j=1; j*j <= i; j++){
                int rem = i - j*j;

                if(dp[rem] == false){
                    dp[i] = true;
                    break;
                }
            }
        }




        return dp[n];


    }
};