class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        set<int> st2;

        for(int i=0;i<nums1.size();i++){
            st.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            st2.insert(nums2[i]);
        }

        auto it1 = st.begin();
        auto it2 = st2.begin();
        vector<int> ans;
        while(it1 != st.end() && it2 != st2.end()){
            if(*it1 == *it2){
                ans.push_back(*it1);
                it1++;
                it2++;
            }
            else if(*it1 < *it2){
                it1++;
            }
            else{
                it2++;
            }
        }

        return ans;
    }
};