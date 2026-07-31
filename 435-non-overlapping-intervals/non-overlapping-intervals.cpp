class Solution {
public:
    struct data{
        int start;
        int end;
        int pos;
    };
    static bool cmp(const data &a, const data &b){
        return a.end < b.end;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<data> arr(n);

        for(int i=0;i<n;i++){
            arr[i].start = intervals[i][0];
            arr[i].end = intervals[i][1];
            arr[i].pos = i+1;
        }

        sort(arr.begin(), arr.end(), cmp);

        int cnt = 1;
        int freetime = arr[0].end;
        for(int i=1; i<n;i++){
            if(arr[i].start >= freetime){
                cnt++;
                freetime = arr[i].end;
            }
        }


        int ans = n - cnt;
        return ans;

    }
};