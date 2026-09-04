class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        bool allOdd = true;
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 1) {
                allOdd = false;
                break;  // no need to keep checking
            }
        }
        if(allOdd){
            return true;
        }

        bool allEven = true;
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 0) {
                allEven = false;
                break;  // no need to keep checking
            }
        }
        if(allEven){
            return true;
        }

        int mini = *min_element(begin(nums1), end(nums1));
        if(mini % 2 == 1) return true;

        

        return false;
    }
};