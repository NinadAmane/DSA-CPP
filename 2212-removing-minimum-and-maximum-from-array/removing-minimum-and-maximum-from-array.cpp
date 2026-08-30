class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        // map<int,int> index; //val , index
        // for(int i=0;i<n;i++){ 
        //     index[nums[i]] = i;
        // }

        // int maxi = *max_element(nums.begin(), nums.end());
        // int mini = *min_element(nums.begin(), nums.end());
        // if(n == 2 && maxi != mini) return 2;
        // int mid = n/2;
        // cout << maxi << " " << mini << " " << endl;
        // int ans = 0;

        // if(index[mini] <= mid && index[maxi] <= mid){
        //     ans = max(index[mini], index[maxi]) + 1;
        // }
        // else if(index[mini] >= mid && index[maxi] >= mid){
        //     ans = max(n - index[mini], n - index[maxi]);
        // }
        // else{
        //     if(index[maxi] <= mid && index[mini] >= mid){
        //         ans = (index[maxi] + 1) + (n - index[mini]);
        //     }
        //     else if(index[maxi] >= mid && index[mini] <= mid){
        //         ans = (index[mini] + 1) + (n - index[maxi]);
        //     }
        // }

        int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();

        int front = max(minIndex, maxIndex) + 1;
        int back = max(n - minIndex, n - maxIndex);

        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        int frontback = left + 1 + (n - right);
        return min({front,back, frontback});
    }
};