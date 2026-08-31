/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> nums;
        ListNode* curr = head;

        while(curr!= NULL){
            nums.push_back(curr->val);
            curr = curr->next;
        }

        vector<int> pivots;

        for(int i=0;i<nums.size();i++){
            if(i == 0 || i == nums.size() - 1) continue;

            if(nums[i-1] > nums[i] && nums[i+1] > nums[i]){
                pivots.push_back(i+1);
            }

            else if(nums[i-1] < nums[i] && nums[i+1] < nums[i]){
                pivots.push_back(i+1);
            }
        }

        for(int x : pivots){
            cout << x << " ";
        }

        if(pivots.empty()) return {-1, -1};
        int n = pivots.size();
        int maxdist = pivots[n-1] - pivots[0];
        int mindist = INT_MAX;

        for(int i=0;i<n-1;i++){
            if(pivots[i+1] - pivots[i] < mindist){
                mindist = pivots[i+1] - pivots[i];
            }
        }
        if(mindist ==0 || maxdist == 0) return {-1, -1};
        return {mindist, maxdist};
        
    }
};