class Solution {
public:
//RECURSIVE: 

    // int f(int ind, int jumps, vector<int>& nums){
    //     int n = nums.size();
    //     if(ind >= n -1){
    //         return jumps;
    //     }
    //     int mini = INT_MAX;
    //     for(int i=1;i<=nums[ind]  && ind + i < n;i++){
    //         mini = min(mini, f(ind + i, jumps + 1, nums));
    //     }

    //     return mini;


    // }
    // int jump(vector<int>& nums) {
    //     int n=nums.size();
    //     // vector<bool> dp(n, false);

    //     return f(0,0,nums);
        
    // }



    //GREEDY:
    int jump(vector<int>& nums) {
        int n=nums.size();
        

        int jumps = 0;

        int farthest = 0;

        int l =0;
        int r = 0;

        while(r<n-1){
            farthest  =0;

            for(int i = l;i<=r;i++){
                farthest = max(farthest, nums[i] + i);
            }

            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;

        
        
    }
};