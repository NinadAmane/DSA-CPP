class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(begin(intervals), end(intervals));
        for(int i=0;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(ans.empty() || ans.back()[1] < start){
                ans.push_back({start, end});
            }
            else{
                auto x = ans.back();
                ans.pop_back();
                if(x[1] >= start){
                    ans.push_back({x[0] , max(x[1], end)});
                }
            }
        }

        return ans;
    }
};