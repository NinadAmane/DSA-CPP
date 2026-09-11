class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n=citations.size();
        int count = 0;
        for(int i=0;i<n;i++){
            int papers = n - i;

            if(citations[i] >= papers){
                count++;
            }
        }
        return count;
    }
};