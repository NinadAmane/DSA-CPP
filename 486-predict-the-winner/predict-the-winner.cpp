class Solution {
public:
    int f(int l, int r, int score1, int score2, bool turn, vector<int>&nums){
        int n=nums.size();
        if(l>r){
            return score1>=score2;
        }
        if(turn){
            return f(l+1,r,score1 + nums[l], score2, false,nums) || 
                    f(l,r-1,score1 + nums[r], score2, false, nums);
        }
        else{
            return f(l+1,r,score1 , score2 + nums[l], true,nums) &&
                    f(l,r-1,score1 , score2 + nums[r], true, nums);
        }

        return false;
        
    }
    bool predictTheWinner(vector<int>& nums) {
        int n= nums.size();
        
        return f(0,n-1,0,0,true,nums);
    }
};