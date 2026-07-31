class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        vector<vector<int>> ans;
        int l = 0;
        int r = n-1;
        int insertpos = n;
        while(l<=r){
            int mid = (l+r)/2;

            if(intervals[mid][0] >= newInterval[0]){
                insertpos = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        
        intervals.insert(intervals.begin() + insertpos, newInterval);

        
        //merging

        for(auto& interval: intervals){
            int first = interval[0]; //4
            int second = interval[1]; //8
            if(ans.empty()){
                ans.push_back(interval);
            }
            else if(ans.back()[1] < first){
                ans.push_back(interval);
            }
            else{
                auto last = ans.back(); //5
                ans.pop_back();
                if(last[1] >= first){
                    ans.push_back({last[0], max(last[1], second)});
                }
            }
        }
        return ans;

    }
};