class Solution {
public:
    int len = 0;
    // int f(int i, vector<int>& arr, int target, int two){
    //     int n = arr.size();
    //     if(i>=n){
    //         if(target == 0){
    //             two--;
    //             if(two ==0){
                    
    //             }
    //         }
    //     }

    //     int skip = f(i+1, arr, target);

    //     int take = 0;
    //     if(target >= arr[i]){
    //         take += f(i+1, arr, target - arr[i]);
    //     }


    // }
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        int l =0;
        int sum = 0;
        int minlen = n+1;
        vector<int> dp(n+1,n);
        for(int r=0;r<n;r++){

            sum += arr[r];

            while(sum > target){
                sum -= arr[l++];
                
            }

            dp[r+1] = dp[r];

            if(sum == target){
                minlen = min(minlen, r - l + 1 + dp[l]);
                dp[r+1] = min(dp[r], r - l + 1);
            }
        }   

        return minlen == n + 1 ? -1 : minlen;
        
    }

        
};